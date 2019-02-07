/**************************************************************************
 * Biblioteca de Pilha		                                              *
 *                                                                        *
 * Biblioteca com operações de pilha							 		  *
 * Autor: João Paulo D. Preti                                             *
 **************************************************************************/
/*
#ifndef CSTACK_H_
#define CSTACK_H_

#define STACK_SIZE 100

typedef struct cStack {
    char elements[STACK_SIZE];
    int top;
    int id;
}cStack;

void init(cStack *stack, int id);
void push(cStack *stack, char element);
char pop(cStack *stack);
char top(cStack *stack);
int isEmpty(cStack *stack);
int isFull(cStack *stack);
int size(cStack *stack);
int capacity(cStack *stack);
void show(cStack *stack);

void init(cStack *stack, int id) {
    stack->top = -1;
    stack->id = id;
}

void push(cStack *stack, char element) {
    if (!isFull(stack)) {
        stack->top++;
        stack->elements[stack->top]=element;
    } else
        printf("Push not allowed: stack is full.\n");
}

char pop(cStack *stack) {
    if (!isEmpty(stack)) {
        stack->top--;
        return stack->elements[stack->top+1];
    } else {
        printf("Pop not allowed: stack is empty.\n");
        return ' ';
    }
}

char top(cStack *stack) {
    return (isEmpty(stack))?' ':stack->elements[stack->top];
}

int isEmpty(cStack *stack) {
    return stack->top==-1;
}

int isFull(cStack *stack) {
    return stack->top==STACK_SIZE-1;
}

int size(cStack *stack) {
    return stack->top+1;
}

int capacity(cStack *stack) {
    return STACK_SIZE;
}

void show(cStack *stack) {
    while (!isEmpty(stack)) {
        printf("%c", pop(stack));
    }
}

#endif /* CSTACK_H_ */
