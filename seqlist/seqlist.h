//
// Created by Administrator on 11月30日 030.
//
#ifndef DATASTRUCT_SEQLIST_H
#define DATASTRUCT_SEQLIST_H

typedef unsigned long DATA_TYPE;
typedef struct {
    DATA_TYPE * memory;
    unsigned int size;
    unsigned int maxSize;
} seqlist_t;

seqlist_t* seqlist_new(unsigned int initSize);
void seqlist_insert(seqlist_t * list, void* data);
void seqlist_merge(seqlist_t * dest, seqlist_t * source);
void seqlist_distinct(seqlist_t * list);
void seqlist_foreach(seqlist_t* list, void (*callback)(unsigned int, void *));
int seqlist_indexof(seqlist_t * list, void* data);

#endif //DATASTRUCT_SEQLIST_H
