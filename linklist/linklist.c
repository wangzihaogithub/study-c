//
// Created by Administrator on 11月30日 030.
//
#include "linklist.h"
#include <stdlib.h>

void linklist_insert_head(linklist *list, void* data){
    linklist * p = linklist_new();
    p->next = list->next;
    p->data = data;
    list->next = p;
}

void linklist_insert_tail(linklist *list, void* data){
    while (1){
        if(list->next){
            list = list->next;
        } else{
            list->next = linklist_new();
            list->next->data = data;
            break;
        }
    }
}

linklist* linklist_new(){
    linklist* list = malloc(sizeof(linknode));
    if(list != NULL){
        list->data = NULL;
        list->next = NULL;
    }
    return list;
}

void linklist_foreach(linklist *list, void (*callback)(unsigned int, void *)){
    unsigned int i = 0;
    while (list->next){
        callback(i,list->next->data);
        i++;
        list = list->next;
    }
}
