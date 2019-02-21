
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void init(LinkedList *list) {
    list->first=list->last=NULL;
    list->size=0;
}
int enqueue(LinkedList *list, void *data) {
    return 1;
}
void* dequeue(LinkedList *list) {
    return NULL;
}
void* first(LinkedList *list) {
    return NULL;
}
void* last(LinkedList *list) {
    return NULL;
}
int push(LinkedList *list, void *data) {
    return 1;
}
void* pop(LinkedList *list) {
    return NULL;
}
void* top(LinkedList *list) {
    return NULL;
}
bool isEmpty(LinkedList *list) {
    
}
int indexOf(LinkedList *list,void *data) {
    return -1;
}
int add(LinkedList *list, int pos, void *data) {
    return 1;
}
int addAll(LinkedList *listDest, int pos, LinkedList *listSource) {
    return 0;
}
void* removePos(LinkedList *listDest, int pos) {
    return NULL;
}
void* removeData(LinkedList *listDest, void *data) {
    return NULL;
}




