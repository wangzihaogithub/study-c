//
// Created by Administrator on 11月30日 030.
//
#ifndef DATASTRUCT_SORTLINKLIST_H
#define DATASTRUCT_SORTLINKLIST_H

typedef unsigned long DATA_TYPE;

typedef struct sortnode{
    int (*comparator)(void *, void *);
    DATA_TYPE * data;
    struct sortnode *next;
} sortlinknode,sortlinklist;

sortlinklist* sortlinklist_new(int (*comparator)(void *, void *));
void sortlinklist_insert_head(sortlinklist *list, void* data);
void sortlinklist_insert_tail(sortlinklist *list, void* data);
void sortlinklist_insert(sortlinklist *list, void* data);
void sortlinklist_foreach(sortlinklist *list, void (*callback)(unsigned int, void *));
void sortlinklist_sort(sortlinklist *list);
void sortlinklist_reverse(sortlinklist* list);

#endif //DATASTRUCT_SORTLINKLIST_H
