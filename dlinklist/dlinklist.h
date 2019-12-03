//
// Created by Administrator on 11月30日 030.
//
#ifndef DATASTRUCT_DLINKLIST_H
#define DATASTRUCT_DLINKLIST_H

typedef char DATA_TYPE;
//typedef unsigned long DATA_TYPE;
typedef struct node{
    DATA_TYPE * data;
    struct node *prior;
    struct node *next;
} dlinknode,dlinklist;

int dlinklist_empty(dlinklist *list);
dlinklist* dlinklist_new();
void dlinklist_insert_head(dlinklist *list, void* data);
void dlinklist_insert_tail(dlinklist *list, void* data);
void dlinklist_foreach(dlinklist *list, void (*callback)(unsigned int, void *));

#endif //DATASTRUCT_DLINKLIST_H
