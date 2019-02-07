//
//  xyQueue.h
//  datastructure
//
//  Created by João Paulo Delgado Preti on 04/08/17.
//  Copyright © 2017 João Paulo Delgado Preti. All rights reserved.
//
/*
#ifndef xyQueue_h
#define xyQueue_h

#include <stdio.h>

#define SIZE 100

typedef struct coordXY {
    int x,y;
}coordXY;

typedef struct xyQueue {
    coordXY elements[SIZE];
    int begin; //For a circular queue
    int size;
    int end;
    int id;
}xyQueue;

void init(xyQueue *queue, int id);
void enqueue(xyQueue *queue, coordXY element);
coordXY dequeue(xyQueue *queue);
coordXY peek(xyQueue *queue);
int isEmpty(xyQueue *queue);
int isFull(xyQueue *queue);
int size(xyQueue *queue);
int capacity(xyQueue *queue);
void show(xyQueue *queue);

void init(xyQueue *queue, int id) {
    queue->begin=queue->end=queue->size=0;
    queue->id = id;
}

void enqueue(xyQueue *queue, coordXY element) {
    if (!isFull(queue)) {
        queue->elements[queue->end] = element;
        queue->end=(queue->end+1==SIZE)?0:queue->end+1;
        queue->size++;
    } else
        printf("Queue Overflow!\n");
}

coordXY dequeue(xyQueue *queue) {
    coordXY aux;
    if (!isEmpty(queue)) {
        aux = queue->elements[queue->begin];
        queue->begin=(queue->begin+1==SIZE)?0:queue->begin+1;
        queue->size--;
    } else {
        printf("Queue Underflow!\n");
    }
    return aux;
}

coordXY peek(xyQueue *queue) {
    return queue->elements[queue->begin];
}

int isEmpty(xyQueue *queue) {
    return queue->size == 0;
}

int isFull(xyQueue *queue) {
    return queue->size == SIZE;
}

int size(xyQueue *queue) {
    return queue->size;
}

int capacity(xyQueue *queue) {
    return SIZE;
}

void show(xyQueue *queue) {
    while (!isEmpty(queue)) {
        coordXY xy = dequeue(queue);
        printf("(%d,%d) ",xy.x, xy.y);
    }
    printf("\n");
}

#endif /* xyQueue_h */
