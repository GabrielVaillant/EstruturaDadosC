//
//  iStack.h
//  datastructure
//
//  Created by João Paulo Delgado Preti on 09/05/17.
//  Copyright © 2017 João Paulo Delgado Preti. All rights reserved.
//
/*
#ifndef iStack_h
#define iStack_h

#define STACK_SIZE 100

typedef struct iStack {
    int elements[STACK_SIZE];
    int top;
    int id;
}iStack;

void init(iStack *stack, int id);
void push(iStack *stack, int element);
int pop(iStack *stack);
int top(iStack *stack);
int isEmpty(iStack *stack);
int isFull(iStack *stack);
int size(iStack *stack);
int capacity(iStack *stack);
void show(iStack *stack);
*/
/*
 * Initialize the stack with an id and with no elements.
 

void init(iStack *stack, int id) {
    stack->top = -1;
    stack->id = id;
}

/*
 * Add a new a element to the top of the stack.
 
void push(iStack *stack, int element) {
    if (!isFull(stack)) {
        stack->top++;
        stack->elements[stack->top]=element;
    } else
        printf("Push not allowed: stack is full.\n");
}

/*
 * Remove the top element of the stack and return it.
 
int pop(iStack *stack) {
    if (!isEmpty(stack)) {
        stack->top--;
        return stack->elements[stack->top+1];
    } else {
        printf("Pop not allowed: stack is empty.\n");
        return -1;
    }
}

/*
 * Return the top element in the stack without removing it.
 
int top(iStack *stack) {
    return isEmpty(stack)?-1:stack->elements[stack->top];
}

/*
 * Returns 0 if it is not empty and 1 otherwise.
 
int isEmpty(iStack *stack) {
    return stack->top==-1;
}

/*
 * Returns 0 if it is not full and 1 otherwise.
 
int isFull(iStack *stack) {
    return stack->top==STACK_SIZE-1;
}

/*
 * Returns the total number of elements in the stack.
 
int size(iStack *stack) {
    return stack->top+1;
}

/*
 * Returns the total memory of the stack. If you want
 * to know how many space is still available you have
 * to decrement it's value from the size function return.
 
int capacity(iStack *stack) {
    return STACK_SIZE;
}

/*
 * Prints all the elements in the stack.
 
void show(iStack *stack) {
    while (!isEmpty(stack)) {
        printf("%d ", pop(stack));
    }
}

#endif /* iStack_h */

