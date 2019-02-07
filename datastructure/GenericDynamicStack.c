#include <stdio.h>
#include <stdlib.h>
#include "GenericDynamicStack.h"

void init(GenericDynamicStack *stack) {
	stack->top = NULL;
	stack->size = 0;
}

int push(GenericDynamicStack *stack, void *data) {
	Node *newNode = (Node*) malloc(sizeof(Node));
	if (newNode==NULL) return -1;
	newNode->data = data;
	newNode->next = stack->top;
	stack->top = newNode;
	stack->size++;
	return 1;
}

void* pop(GenericDynamicStack *stack) {
    if (stack->top!=NULL) {
        Node *aux = stack->top;
        stack->top = stack->top->next;
        free(aux);
        return aux->data; //não faça isso após o free para aplicações concorrentes
    }
    return NULL;
}

void* top(GenericDynamicStack *stack) {
    if (stack->top!=NULL)
        return stack->top->data;
    else
        return NULL;
}

int main() {
	GenericDynamicStack stack;
	init(&stack);
    int *aux = (int *)malloc(sizeof(int));
    *aux=1;
	push(&stack, aux);
    aux = (int *)malloc(sizeof(int));
    *aux=2;
	push(&stack, aux);
    aux = (int *)malloc(sizeof(int));
    *aux=3;
	push(&stack, aux);
    
    printf("%d\n",*((int*)top(&stack)));
    printf("%d\n",*((int*)pop(&stack)));
    printf("%d\n",*((int*)pop(&stack)));
    printf("%d\n",*((int*)pop(&stack)));
    //printf("%d\n",*((int*)pop(&stack)));
    
	return 0;
}




