//
//  ListaSimplesmenteLigada.h
//  EstruturaDeDados
//
//  Created by João Paulo Delgado Preti.
//  Copyright (c) 2014 João Paulo Delgado Preti. All rights reserved.
//

#ifndef EstruturaDeDados_GenericDynamicStack_h
#define EstruturaDeDados_GenericDynamicStack_h

typedef struct Node {
    void *data;
    struct Node *next;
}Node;

typedef struct GenericDynamicStack {
    Node *top;
    int size;
}GenericDynamicStack;

void init(GenericDynamicStack *stack);
int push(GenericDynamicStack *stack, void *data);
void* pop(GenericDynamicStack *stack);
void* top(GenericDynamicStack *stack);

#endif
