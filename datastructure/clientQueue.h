//
//  clientQueue.h
//  datastructure
//
//  Created by João Paulo Delgado Preti on 14/07/17.
//  Copyright © 2017 João Paulo Delgado Preti. All rights reserved.
//
/*
#ifndef clientQueue_h
#define clientQueue_h

#include <stdio.h>

#define SIZE 10000

typedef struct regClient {
    int id,arrivalTime, workTime;
}regClient;

typedef struct regClientQueue {
    regClient elements[SIZE];
    int begin; //For a circular queue
    int size;
    int end;
    int id;
}regClientQueue;

void init(regClientQueue *queue, int id);
void enqueue(regClientQueue *queue, regClient element);
regClient dequeue(regClientQueue *queue);
regClient peek(regClientQueue *queue);
int isEmpty(regClientQueue *queue);
int isFull(regClientQueue *queue);
int size(regClientQueue *queue);
int capacity(regClientQueue *queue);
void show(regClientQueue *queue);

void init(regClientQueue *queue, int id) {
    queue->begin=queue->end=queue->size=0;
    queue->id = id;
}

void enqueue(regClientQueue *queue, regClient element) {
    if (!isFull(queue)) {
        queue->elements[queue->end] = element;
        queue->end=(queue->end+1==SIZE)?0:queue->end+1;
        queue->size++;
    } else
        printf("Queue Overflow!\n");
}

regClient dequeue(regClientQueue *queue) {
    regClient aux;
    if (!isEmpty(queue)) {
        aux = queue->elements[queue->begin];
        queue->begin=(queue->begin+1==SIZE)?0:queue->begin+1;
        queue->size--;
    } else {
        printf("Queue Underflow!\n");
    }
    return aux;
}

regClient peek(regClientQueue *queue) {
    return queue->elements[queue->begin];
}

int isEmpty(regClientQueue *queue) {
    return queue->size == 0;
}

int isFull(regClientQueue *queue) {
    return queue->size == SIZE;
}

int size(regClientQueue *queue) {
    return queue->size;
}

int capacity(regClientQueue *queue) {
    return SIZE;
}

void show(regClientQueue *queue) {
    while (!isEmpty(queue)) {
        regClient aux = dequeue(queue);
        printf("(id:%d time:%d\n) ",aux.id, aux.workTime);
    }
}

#endif /* clientQueue_h */
