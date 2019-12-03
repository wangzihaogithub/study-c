#include <stdio.h>
#include "seqlist.h"

void print_seqlist(unsigned int index, void* data){
    printf("data[%d] = %s\n",index, data);
}

int main(){
    printf("distinct=case-1=====\n");
    seqlist_t* seqlist1 = seqlist_new(3);
    seqlist_insert(seqlist1,"1");
    seqlist_insert(seqlist1,"1");
    seqlist_insert(seqlist1,"2");
    seqlist_insert(seqlist1,"3");
    seqlist_distinct(seqlist1);
    seqlist_foreach(seqlist1, print_seqlist);

    printf("distinct=case-2=====\n");
    seqlist_t* seqlist2 = seqlist_new(3);
    seqlist_insert(seqlist2,"2");
    seqlist_insert(seqlist2,"1");
    seqlist_insert(seqlist2,"1");
    seqlist_insert(seqlist2,"3");
    seqlist_distinct(seqlist2);
    seqlist_foreach(seqlist2, print_seqlist);

    printf("distinct=case-3=====\n\n");
    seqlist_t* seqlist3 = seqlist_new(3);
    seqlist_insert(seqlist3,"2");
    seqlist_insert(seqlist3,"3");
    seqlist_insert(seqlist3,"1");
    seqlist_insert(seqlist3,"1");
    seqlist_distinct(seqlist3);
    seqlist_foreach(seqlist3, print_seqlist);


    printf("merge==============\n");
    seqlist_t* destlist = seqlist_new(3);
    seqlist_insert(destlist, "1");
    seqlist_insert(destlist, "2");
    seqlist_insert(destlist, "3");

    seqlist_t* sourcelist = seqlist_new(3);
    seqlist_insert(sourcelist, "2");
    seqlist_insert(sourcelist, "3");
    seqlist_insert(sourcelist, "4");

    seqlist_merge(destlist, sourcelist);
    seqlist_foreach(destlist, print_seqlist);
    return 0;
}


