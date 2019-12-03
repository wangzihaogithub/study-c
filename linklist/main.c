#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linklist.h"

void print_linklist(unsigned int index, void* data){
    printf("data[%d] = %s\n",index, data);
}

void free_linklist(unsigned int index, void* data){
    printf("free data[%d] = %s\n",index, data);
    free(data);
}

int main(){
    linklist *list = linklist_new();
    linklist_insert_head(list,"1");
    linklist_insert_head(list,"2");
    linklist_insert_head(list,"3");
    linklist_insert_tail(list,"1");
    linklist_insert_tail(list,"2");
    linklist_insert_tail(list,"3");
    linklist_foreach(list,print_linklist);

    linklist *scanflist = linklist_new();
    while (1) {
        char *input = malloc(11);
        printf("input str. max len=10. ('-1' = exit) \n");
        scanf("%s", input);
        linklist_insert_tail(scanflist,input);
        if(strcmp("-1",input) == 0){
            break;
        }
    }
    linklist_foreach(scanflist,print_linklist);
    linklist_foreach(scanflist,free_linklist);
    return 0;
}


