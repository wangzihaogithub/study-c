//
// Created by Administrator on 11月30日 030.
//
#include "seqlist.h"
#include <stdlib.h>

DATA_TYPE NULL_DATA = (DATA_TYPE) NULL;

int resize(seqlist_t* list, unsigned int newMaxSize){
    void * newMemory = realloc(list->memory,newMaxSize * sizeof(DATA_TYPE));
    if(newMemory == NULL){
        return 0;
    } else {
        list->memory = newMemory;
        list->maxSize = newMaxSize;
        return 1;
    }
}

int seqlist_indexof(seqlist_t * list, void* data){
    DATA_TYPE p_data = (DATA_TYPE) data;
    for (unsigned int i = 0; i < list->size; i++) {
        if(list->memory[i] == p_data){
            return (int)i;
        }
    }
    return -1;
}

void seqlist_merge(seqlist_t * dest, seqlist_t * source){
    for (unsigned int i = 0; i < source->size; i++) {
        void * value = (void*) source->memory[i];
        if(seqlist_indexof(dest, value) == -1){
            seqlist_insert(dest, value);
        }
    }
}

void seqlist_insert(seqlist_t * list, void* data){
    if(data == NULL){
        return;
    }
    if(list->size == list->maxSize){
        if(!resize(list,list->maxSize * 2)){
            exit(1);
        }
    }
    list->memory[list->size] = (DATA_TYPE)data;
    list->size++;
}

void seqlist_distinct(seqlist_t * list){
    if(list == NULL || list->size == 0){
        return;
    }
    int nullValueIndex = -1;
    int size = (int)list->size;
    for(unsigned int i=0; i < size; i++){
        //去重
        for(unsigned int j=0; j < size; j++){
            if(list->memory[i] == list->memory[j] && j != i) {
                list->memory[j] = NULL_DATA;
                list->size--;
            }
        }
        //向左填满空数据
        if (list->memory[i] == NULL_DATA) {
            nullValueIndex = (int)i;
        } else if (nullValueIndex != -1) {
            list->memory[nullValueIndex] = list->memory[i];
            list->memory[i] = NULL_DATA;
            nullValueIndex= (int)i;
        }
    }
}

seqlist_t* seqlist_new(unsigned int initSize){
    seqlist_t* list = malloc(sizeof(seqlist_t));
    if(list != NULL){
        list->memory = malloc(initSize * sizeof(DATA_TYPE));
        list->size = 0;
        list->maxSize = initSize;
    }
    return list;
}

void seqlist_foreach(seqlist_t* list, void (*callback)(unsigned int, void *)){
    for (unsigned int i = 0; i < list->size; i++) {
        callback(i, (void *) list->memory[i]);
    }
}
