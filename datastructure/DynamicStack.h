//
//  ListaSimplesmenteLigada.h
//  EstruturaDeDados
//
//  Created by João Paulo Delgado Preti.
//  Copyright (c) 2014 João Paulo Delgado Preti. All rights reserved.
//

#ifndef EstruturaDeDados_DynamicStack_h
#define EstruturaDeDados_DynamicStack_h

typedef struct Node {
    int data;
    struct Node *next;
}Node;

typedef struct DynamicStack {
    Node *top;
    int size;
}DynamicStack;

void init(DynamicStack *stack);
int push(DynamicStack *stack, int data);
int pop(DynamicStack *stack);
int top(DynamicStack *stack);

#endif
