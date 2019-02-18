/*
#include <stdio.h>
#include <stdlib.h>
#include "DynamicStack.h"

void init(DynamicStack *stack) {
	stack->top = NULL;
	stack->size = 0;
}

int push(DynamicStack *stack, int data) {
	Node *newNode = (Node*) malloc(sizeof(Node));
	if (newNode==NULL) return -1;
	newNode->data = data;
	newNode->next = stack->top;
	stack->top = newNode;
	stack->size++;
	return 1;
}

int pop(DynamicStack *stack) {
    if (stack->top!=NULL) {
        Node *aux = stack->top;
        stack->top = stack->top->next;
        free(aux);
        return aux->data; //não faça isso após o free para aplicações concorrentes
    }
    return -1;
}

int top(DynamicStack *stack) {
    if (stack->top!=NULL)
        return stack->top->data;
    else
        return -1;
}

int main() {
	DynamicStack stack;
	init(&stack);
	push(&stack, 1);
	push(&stack, 2);
	push(&stack, 3);
    printf("%d\n",top(&stack));
    printf("%d\n",pop(&stack));
    printf("%d\n",pop(&stack));
    printf("%d\n",pop(&stack));
    printf("%d\n",pop(&stack));
    
	return 0;
}
*/



