
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void init(LinkedList *list) {
    list->first=list->last=NULL;
    list->size=0;
}

int enqueue(LinkedList *list, void *data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode==NULL) return -1;
    newNode->data = data;
    newNode->next=NULL;
    if (isEmpty(list)) {
        list->first=list->last=newNode;
    } else {
        list->last->next=newNode;
        list->last = newNode;
    }
    list->size++;
    return 1;
}

void* dequeue(LinkedList *list) {
    if (isEmpty(list)) return NULL;
    Node *aux = list->first;
    list->first=list->first->next;
    void *auxReturn = aux->data;
    free(aux);
    if (isEmpty(list)) init(list);
    list->size--;
    return auxReturn;
}

void* first(LinkedList *list) {
    return (isEmpty(list))?NULL:list->first->data;
}

void* last(LinkedList *list) {
    return (isEmpty(list))?NULL:list->last->data;
}

int push(LinkedList *list, void *data) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    if (newNode==NULL) return -1;
    newNode->data = data;
    newNode->next = list->first;
    list->first = newNode;
    list->size++;
    return 1;
}

void* pop(LinkedList *list) {
    if (isEmpty(list)) return NULL;
    Node *aux = list->first;
    list->first = list->first->next;
    void *auxReturn = aux->data;
    free(aux);
    return auxReturn;
}

void* top(LinkedList *list) {
    return first(list);
}

bool isEmpty(LinkedList *list) {
    return (list->first==NULL);
}

int indexOf(LinkedList *list,void *data,compare equal) {
    if (isEmpty(list)) return -1;
    int count=0;
    Node *aux = list->first;
    
    //while(aux!=NULL && aux->data!=data) { //versão sem ponteiro para função
    while(aux!=NULL && !equal(aux->data,data)) {
        aux=aux->next;
        count++;
    }
    
    return (aux==NULL)?-1:count;
}

void* getPos(LinkedList *list,int pos) {
    if (isEmpty(list) || pos>=list->size) return NULL;
    Node *aux = list->first;
    for (int count=0;(aux!=NULL && count<pos);count++,aux=aux->next);
    return aux->data;
}

Node* getNodeByPos(LinkedList *list,int pos) {
    if (isEmpty(list) || pos>=list->size) return NULL;
    Node *aux = list->first;
    for (int count=0;(aux!=NULL && count<pos);count++,aux=aux->next);
    return aux;
}

int add(LinkedList *list, int pos, void *data) {
    Node *aux = getNodeByPos(list, pos);
    if (aux==NULL) return -2;
    
    Node *newNode = (Node*) malloc(sizeof(Node));
    if (newNode==NULL) return -1;
    
    newNode->data = data;
    newNode->next = NULL;
    
    newNode->next = aux->next;
    aux->next = newNode;
    
    list->size++;
    
    return 1;
}

int addAll(LinkedList *listDest, int pos, LinkedList *listSource) {
    Node *aux = getNodeByPos(listDest, pos);
    if (aux==NULL) return -2;
    
    if (isEmpty(listSource)) return -1;
    
    listSource->last->next = aux->next;
    aux->next = listSource->first;
    
    listDest->size+=listSource->size;
    
    return listSource->size;
}

void* removePos(LinkedList *list, int pos) {
    if (isEmpty(list) || pos>=list->size) return NULL;
    
    //Se for o primeiro elemento
    if (pos==0) return dequeue(list);
    
    Node *nodeRemove = NULL;
    Node *aux = NULL;

    aux = getNodeByPos(list, pos-1);
    nodeRemove = aux->next;
    aux->next = nodeRemove->next;
    
    //Se for o último elemento
    if (pos+1==list->size) {
        list->last = aux;
    }
    
    void* dataRemove = nodeRemove->data;
    free(nodeRemove);
    list->size--;
    
    return dataRemove;
}

int removeData(LinkedList *list, void *data, compare equal) {
    if (isEmpty(list)) return -1;
    
    if (equal(list->first->data,data)) {
        free(dequeue(list));
        list->size--;
        return 1;
    }
    
    if (equal(list->last->data,data)) {
        free(removePos(list, list->size-1));
        list->size--;
        return 1;
    }
    
    Node *aux = list->first;
    while(aux->next!=NULL && !equal(aux->next->data,data))
        aux=aux->next;
    
    if (aux->next!=NULL) {
        Node *nodeRemove = aux->next;
        aux->next = nodeRemove->next;
        free(nodeRemove->data);
        free(nodeRemove);
        list->size--;
        return 1;
    } else {
        return 0;
    }
}

bool compara(void *data1, void *data2) {
    int *d1 = (int*)data1;
    int *d2 = (int*)data2;
    
    return (*d1==*d2)?true:false;
}


int main() {
    LinkedList list;
    init(&list);
    
    int *aux = (int *)malloc(sizeof(int));
    *aux=1;
    enqueue(&list, aux);
    aux = (int *)malloc(sizeof(int));
    *aux=2;
    enqueue(&list, aux);
    aux = (int *)malloc(sizeof(int));
    *aux=3;
    enqueue(&list, aux);
    
    printf("%d\n",*((int*)first(&list)));
    printf("%d\n",indexOf(&list,aux,compara));
    printf("%d\n",*((int*)getPos(&list,2)));
    printf("%d\n",*((int*)dequeue(&list)));
    printf("%d\n",*((int*)dequeue(&list)));
    printf("%d\n",*((int*)dequeue(&list)));
    //printf("%d\n",*((int*)dequeue(&stack)));
    
    return 0;
}




