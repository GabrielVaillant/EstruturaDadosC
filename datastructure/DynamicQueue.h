//
//
//  EstruturaDeDados
//
//  Created by João Paulo Delgado Preti.
//  Copyright (c) 2014 João Paulo Delgado Preti. All rights reserved.
//

#ifndef EstruturaDeDados_DynamicQueue_h
#define EstruturaDeDados_DynamicQueue_h

typedef struct Node {
    void *data;
    struct Node *next;
}Node;

typedef struct DynamicQueue {
    Node *first;
    Node *last;
    int size;
}DynamicQueue;

void init(DynamicQueue *queue);
int enqueue(DynamicQueue *queue, void *data);
void* dequeue(DynamicQueue *queue);
void* first(DynamicQueue *queue);

#endif

