//
// Created by Administrator on 11月30日 030.
//
#ifndef DATASTRUCT_LINKLIST_H
#define DATASTRUCT_LINKLIST_H

typedef unsigned long DATA_TYPE;
typedef struct node{
    DATA_TYPE * data;
    struct node *next;
} linknode,linklist;

linklist* linklist_new();
void linklist_insert_head(linklist *list, void* data);
void linklist_insert_tail(linklist *list, void* data);
void linklist_foreach(linklist *list, void (*callback)(unsigned int, void *));

#endif //DATASTRUCT_LINKLIST_H
