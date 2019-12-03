#include <stdio.h>
#include <stdlib.h>
#include "dlinklist.h"

void print_dlinklist(unsigned int index, void* data){
    printf("data[%d] = %s\n",index, data);
}

int main(){
    dlinklist *headlist = dlinklist_new();
    dlinklist_insert_head(headlist,"1");
    dlinklist_insert_head(headlist,"2");
    dlinklist_insert_head(headlist,"3");
    dlinklist_insert_head(headlist,"4");
    dlinklist_insert_head(headlist,"5");
    dlinklist_insert_head(headlist,"6");
    dlinklist_foreach(headlist,print_dlinklist);

    dlinklist *taillist = dlinklist_new();
    dlinklist_insert_tail(taillist,"1");
    dlinklist_insert_tail(taillist,"2");
    dlinklist_insert_tail(taillist,"3");
    dlinklist_insert_tail(taillist,"4");
    dlinklist_insert_tail(taillist,"5");
    dlinklist_insert_tail(taillist,"6");
    dlinklist_foreach(taillist,print_dlinklist);
    return 0;
}


