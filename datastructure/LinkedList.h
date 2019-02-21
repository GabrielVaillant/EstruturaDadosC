//
//
//  EstruturaDeDados
//
//  Created by João Paulo Delgado Preti.
//  Copyright (c) 2014 João Paulo Delgado Preti. All rights reserved.
//

#ifndef EstruturaDeDados_LinkedList_h
#define EstruturaDeDados_LinkedList_h

typedef struct Node {
    void *data;
    struct Node *next;
}Node;

typedef struct LinkedList {
    Node *first;
    Node *last;
    int size;
}LinkedList;

void init(LinkedList *list);
int enqueue(LinkedList *list, void *data);
void* dequeue(LinkedList *list);
void* first(LinkedList *list);
void* last(LinkedList *list);
int push(LinkedList *list, void *data);
void* pop(LinkedList *list);
void* top(LinkedList *list);
bool isEmpty(LinkedList *list);
int indexOf(LinkedList *list,void *data);
void* getPos(LinkedList *list,int pos);
int add(LinkedList *list, int pos, void *data);
int addAll(LinkedList *listDest, int pos, LinkedList *listSource);
void* removePos(LinkedList *listDest, int pos);
void* removeData(LinkedList *listDest, void *data);
#endif

