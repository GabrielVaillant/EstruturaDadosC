//
//  iDoubleStack.h
//  datastructure
//
//  Created by João Paulo Delgado Preti on 23/06/17.
//  Copyright © 2017 João Paulo Delgado Preti. All rights reserved.
//
/*
#ifndef iDoubleStack_h
#define iDoubleStack_h

#define SIZE 100

typedef struct iDblStack {
    int elements[SIZE];
    int top1=-2;
    int top2=-2;
}iDblStack;

void init(iDblStack *stack, int idStack);
void push(iDblStack *stack, int idStack, int element);
int pop(iDblStack *stack, int idStack);
int top(iDblStack *stack, int idStack);
int isEmpty(iDblStack *stack, int idStack);
int isFull(iDblStack *stack);
int size(iDblStack *stack, int idStack);
int capacity(iDblStack *stack, int idStack);
void show(iDblStack *stack, int idStack);

void init(iDblStack *stack, int idStack) {
    if (idStack==1) {
        stack->top1 = -1;
        if (stack->top2==-2) stack->top2=SIZE;
    } else {
        stack->top2 = SIZE;
        if (stack->top1==-2) stack->top1=-1;
    }
}

void push(iDblStack *stack, int idStack, int element) {
    if (!isFull(stack)) {
        if (idStack==1) {
            stack->top1++;
            stack->elements[stack->top1]=element;
        } else {
            stack->top2--;
            stack->elements[stack->top2]=element;
        }
    } else
        printf("Push not allowed: stack is full.\n");
}

int pop(iDblStack *stack, int idStack) {
    if (idStack==1) {
        if (!isEmpty(stack, 1)) {
            stack->top1--;
            return stack->elements[stack->top1+1];
        } else {
            printf("Pop not allowed: stack is empty.\n");
            return -1;
        }
    } else {
        if (!isEmpty(stack, idStack)) {
            stack->top2++;
            return stack->elements[stack->top2-1];
        } else {
            printf("Pop not allowed: stack is empty.\n");
            return -1;
        }
    }
}

int top(iDblStack *stack, int idStack) {
    if (idStack==1)
        return (isEmpty(stack,1))?-1:stack->elements[stack->top1];
    else
        return (isEmpty(stack,idStack))?-1:stack->elements[stack->top2];
}

int isEmpty(iDblStack *stack, int idStack) {
    if (idStack==1)
        return stack->top1==-1;
    else
        return stack->top2==SIZE;
}

int isFull(iDblStack *stack) {
    return stack->top1+1==stack->top2;
}

int size(iDblStack *stack, int idStack) {
    if (idStack==1)
        return stack->top1+1;
    else
        return SIZE-stack->top2;
}

int capacity(iDblStack *stack, int idStack) {
    if (idStack==1)
        return size(stack, 1) + (stack->top2-stack->top1+1);
    else {
        return size(stack, idStack) + (stack->top2-stack->top1+1);
    }
}

void show(iDblStack *stack, int idStack) {
    if (idStack==1)
        while (!isEmpty(stack,1)) {
            printf("%d", pop(stack,1));
        }
    else
        while (!isEmpty(stack,idStack)) {
            printf("%d", pop(stack,idStack));
        }
}

#endif /* iDoubleStack_h */
