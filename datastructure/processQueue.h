//
//  processQueue.h
//  datastructure
//
//  Created by João Paulo Delgado Preti on 19/07/17.
//  Copyright © 2017 João Paulo Delgado Preti. All rights reserved.
//
/*
#ifndef processQueue_h
#define processQueue_h

#include <stdio.h>

#define SIZE 100

typedef struct process {
    int id;
    int workingTime;
    int processedTime;
    int numberOfAllocations;
}process;

typedef struct processQueue {
    process elements[SIZE];
    int begin; //For a circular queue
    int size;
    int end;
    int id;
}processQueue;

void init(processQueue *queue, int id);
void enqueue(processQueue *queue, process element);
process dequeue(processQueue *queue);
process peek(processQueue *queue);
int isEmpty(processQueue *queue);
int isFull(processQueue *queue);
int size(processQueue *queue);
int capacity(processQueue *queue);
void show(processQueue *queue);
process get(processQueue *queue, int i);

void init(processQueue *queue, int id) {
    queue->begin=queue->end=queue->size=0;
    queue->id = id;
}

void enqueue(processQueue *queue, process element) {
    if (!isFull(queue)) {
        queue->elements[queue->end] = element;
        queue->end=(queue->end+1==SIZE)?0:queue->end+1;
        queue->size++;
    } else
        printf("Queue Overflow!\n");
}

process dequeue(processQueue *queue) {
    process aux;
    if (!isEmpty(queue)) {
        aux = queue->elements[queue->begin];
        queue->begin=(queue->begin+1==SIZE)?0:queue->begin+1;
        queue->size--;
    } else {
        printf("Queue Underflow!\n");
    }
    return aux;
}

process peek(processQueue *queue) {
    return queue->elements[queue->begin];
}

int isEmpty(processQueue *queue) {
    return queue->size == 0;
}

int isFull(processQueue *queue) {
    return queue->size == SIZE;
}

int size(processQueue *queue) {
    return queue->size;
}

int capacity(processQueue *queue) {
    return SIZE;
}

void show(processQueue *queue) {
    while (!isEmpty(queue)) {
        process proc = dequeue(queue);
        printf("(%d,%d) ",proc.id, proc.workingTime);
    }
    printf("\n");
}

process get(processQueue *queue, int i) {
    return (queue->elements[i]);
}

#endif /* processQueue_h */
