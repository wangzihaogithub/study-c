//
// Created by Administrator on 11月30日 030.
//
#include "sortlinklist.h"
#include <stdlib.h>

void sortlinklist_insert_head(sortlinklist *list, void* data){
    sortlinklist * node = sortlinklist_new(list->comparator);
    node->next = list->next;
    node->data = data;
    list->next = node;
}

void sortlinklist_insert_tail(sortlinklist *list, void* data){
    while (1){
        if(list->next){
            list = list->next;
        } else{
            list->next = sortlinklist_new(list->comparator);
            list->next->data = data;
            break;
        }
    }
}

void sortlinklist_insert(sortlinklist *list, void* data){
    while(list->next && list->comparator(list->next->data, data) < 0){
        list = list->next;
    }
    sortlinknode* node = sortlinklist_new(list->comparator);
    node->next = list->next;
    node->data = data;
    list->next = node;
}

void sortlinklist_reverse(sortlinklist* list){
    sortlinknode *next = list->next;
    list->next = NULL;
    while(next){
        sortlinknode *nextTmp = next;
        next = next->next;

        nextTmp->next = list->next;
        list->next = nextTmp;
    }
}

sortlinklist* sortlinklist_new(int (*comparator)(void *, void *)){
    sortlinklist* list = malloc(sizeof(sortlinklist));
    if(list != NULL){
        list->comparator = comparator;
        list->next = NULL;
    }
    return list;
}

void sortlinklist_foreach(sortlinklist *list, void (*callback)(unsigned int, void *)){
    unsigned int i = 0;
    while ((list = list->next)){
        callback(i++,list->data);
    }
}

void sortlinklist_sort(sortlinklist *list){
    sortlinknode *next = list->next;
    list->next = NULL;
    while(next){
        sortlinknode *nextTmp = next;
        next=next->next;

        sortlinknode *find = list;
        while(find->next && list->comparator(find->next->data , nextTmp->data) < 0){
            find=find->next;
        }

        nextTmp->next = find->next;
        find->next = nextTmp;
    }
}
