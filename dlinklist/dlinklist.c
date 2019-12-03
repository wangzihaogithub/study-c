//
// Created by Administrator on 11月30日 030.
//
#include "dlinklist.h"
#include <stdlib.h>

int dlinklist_empty(dlinklist *list){
    return list->prior ==  list->next;
}

void dlinklist_insert_head(dlinklist *list, void* data){
    dlinklist * newnode = dlinklist_new();
    newnode->data = data;

    dlinknode * oldnext = list->next;
    list->next = newnode;
    oldnext->prior = newnode;
    newnode->prior = list;
    newnode->next = oldnext;
}

void dlinklist_insert_tail(dlinklist *list, void* data){
    dlinklist * newnode = dlinklist_new();
    newnode->data = data;

    dlinknode * oldprior = list->prior;
    list->prior = newnode;
    oldprior->next = newnode;
    newnode->next = list;
    newnode->prior = oldprior;
}

dlinklist* dlinklist_new(){
    dlinklist* list = malloc(sizeof(dlinknode));
    if(list != NULL){
        list->data = NULL;
        list->prior = list;
        list->next = list;
    }
    return list;
}

void dlinklist_foreach(dlinklist *list, void (*callback)(unsigned int, void *)){
    unsigned int i = 0;
    dlinknode *node = list;
    while (node->next != list){
        callback(i,node->next->data);
        i++;
        node = node->next;
    }
}
