#include <stdio.h>
#include "sortlinklist.h"

typedef struct {
    int key;
    char *value;
} mydata;

void print_sortlinklist(unsigned int index, void* data){
    mydata *my = ((mydata*)data);
    printf("data[%d] = {key=%d, value=%s} \n",index, my->key, my->value);
}

int comparatorInt(void* p1, void *p2){
    int key1 = ((mydata*)p1)->key;
    int key2 = ((mydata*)p2)->key;
    return key1 > key2? 1 : -1;
}

int main(){
    mydata mydata1 = {1,"mydata1"};
    mydata mydata2 = {2,"mydata2"};
    mydata mydata3 = {3,"mydata3"};
    sortlinklist *list = sortlinklist_new(comparatorInt);

    printf("排序插入=====\n");
    sortlinklist_insert(list, &mydata2);
    sortlinklist_insert(list, &mydata1);
    sortlinklist_insert(list, &mydata2);
    sortlinklist_insert(list, &mydata3);
    sortlinklist_foreach(list, print_sortlinklist);

    printf("翻转=====\n");
    sortlinklist_reverse(list);//
    sortlinklist_foreach(list, print_sortlinklist);

    printf("排序函数=====\n");
    sortlinklist *sortlist = sortlinklist_new(comparatorInt);
    sortlinklist_insert_head(sortlist, &mydata1);
    sortlinklist_insert_head(sortlist, &mydata2);
    sortlinklist_insert_head(sortlist, &mydata3);
    sortlinklist_insert_head(sortlist, &mydata1);
    sortlinklist_sort(sortlist);
    sortlinklist_foreach(sortlist, print_sortlinklist);
    return 0;
}


