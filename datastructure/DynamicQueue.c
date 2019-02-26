/*
#include <stdio.h>
#include <stdlib.h>
#include "DynamicQueue.h"

void init(DynamicQueue *queue) {
    //Node* nodeTrash = (Node*)malloc(sizeof(Node));
    //nodeTrash->data = NULL;
    //nodeTrash->next = NULL;
    //queue->first = queue->last=nodeTrash;
    queue->first = queue->last=NULL;
    queue->size = 0;
    
}
//-1 status de memória cheia
int enqueue(DynamicQueue *queue, void *data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode==NULL) return -1;
    newNode->data = data;
    newNode->next=NULL;
    if (queue->first==NULL) { //desnecessario
        queue->first=queue->last=newNode; //desnecessario
    } else {//desnecessario
        queue->last->next=newNode;
        queue->last = newNode;
    }
    queue->size++;
    return 1;
}

void* dequeue(DynamicQueue *queue) {
    if (queue->first==NULL) return NULL;//queue->first->data==NULL
    Node *aux = queue->first;
    queue->first=queue->first->next;
    void *auxReturn = aux->data;
    free(aux);
    if (queue->size==0) init(queue);//foi realizado apenas para garantir que alcance o mesmo estado de quando a fila foi inicializada ou faça queue->last=NULL;
    queue->size--;
    return auxReturn;
}

void* first(DynamicQueue *queue) {
    return (queue->first==NULL)?NULL:queue->first->data;
}

int main() {
	DynamicQueue queue;
	init(&queue);

    int *aux = (int *)malloc(sizeof(int));
    *aux=1;
    enqueue(&queue, aux);
    aux = (int *)malloc(sizeof(int));
    *aux=2;
    enqueue(&queue, aux);
    aux = (int *)malloc(sizeof(int));
    *aux=3;
    enqueue(&queue, aux);
    
    printf("%d\n",*((int*)first(&queue)));
    printf("%d\n",*((int*)dequeue(&queue)));
    printf("%d\n",*((int*)dequeue(&queue)));
    printf("%d\n",*((int*)dequeue(&queue)));
    //printf("%d\n",*((int*)dequeue(&stack)));
    
	return 0;
}
*/



