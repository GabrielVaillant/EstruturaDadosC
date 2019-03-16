
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void init(LinkedList *list) {
    //list->first=list->last=NULL; versão sem trashNode e Circular
    Node *trashNode = (Node*)malloc(sizeof(Node));
    trashNode->data=NULL;
    trashNode->next=trashNode;
    list->last=trashNode;
    list->size=0;
}

int enqueue(LinkedList *list, void *data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode==NULL) return -1;
    newNode->data = data;
    newNode->next=NULL;

//Quando não era circular
//    if (isEmpty(list)) {
//        list->first=list->last=newNode;
//    } else {
//        list->last->next=newNode;
//        list->last = newNode;
//    }
    
    newNode->next = list->last->next;
    list->last->next = newNode;
    list->last = newNode;
    
    list->size++;
    return 1;
}

void* dequeue(LinkedList *list) {
    if (isEmpty(list)) return NULL;

//Quando não era circular
//    Node *aux = list->first;
//    list->first=list->first->next;
//    void *auxReturn = aux->data;
//    free(aux);
//    if (isEmpty(list)) init(list);
//    list->size--;
//    return auxReturn;
    
    Node *trash = list->last->next;
    Node *first = trash->next;

    trash->next = first->next;
    
    void *data = first->data;

    free(first);
    list->size--;
    
    return data;
}

void* first(LinkedList *list) {
    //return (isEmpty(list))?NULL:list->first->data;
    return (isEmpty(list))?NULL:list->last->next->next->data;
}

void* last(LinkedList *list) {
    return (isEmpty(list))?NULL:list->last->data;
}

int push(LinkedList *list, void *data) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    if (newNode==NULL) return -1;
    newNode->data = data;

//Quando não era circular
//    newNode->next = list->first;
//    list->first = newNode;
//    list->size++;
    
    Node *trash = list->last->next;
    Node *first = trash->next;
    
    newNode->next = first;
    trash->next = newNode;
    
    list->size++;
    
    return 1;
}

void* pop(LinkedList *list) {
//    if (isEmpty(list)) return NULL;
//    Node *aux = list->first;
//    list->first = list->first->next;
//    void *auxReturn = aux->data;
//    free(aux);
//    return auxReturn;
    return dequeue(list);
}

void* top(LinkedList *list) {
    return first(list);
}

bool isEmpty(LinkedList *list) {
    //return (list->first==NULL);
    return (list->size==0);
}

int indexOf(LinkedList *list,void *data,compare equal) {
    if (isEmpty(list)) return -1;
    int count=0;
    //Node *aux = list->first;
    Node *aux = list->last->next->next; //que é o first
    
    //while(aux!=NULL && aux->data!=data) { //versão sem ponteiro para função
    //while(aux!=NULL && !equal(aux->data,data)) { //versão sem ser circular
    while(aux!=list->last->next && !equal(aux->data,data)) {
        aux=aux->next;
        count++;
    }
    
    //return (aux==NULL)?-1:count; // versão sem ser circular
    return (aux==list->last->next)?-1:count;
}

void* getPos(LinkedList *list,int pos) {
    if (isEmpty(list) || pos>=list->size) return NULL;
    //Node *aux = list->first;
    Node *aux = list->last->next->next; //é o first
    //for (int count=0;(aux!=NULL && count<pos);count++,aux=aux->next);
    for (int count=0;(aux!=list->last->next && count<pos);count++,aux=aux->next);
    return aux->data;
}

Node* getNodeByPos(LinkedList *list,int pos) {
    if (isEmpty(list) || pos>=list->size) return NULL;
    //Node *aux = list->first;
    Node *aux = list->last->next->next; //é o first
    //for (int count=0;(aux!=NULL && count<pos);count++,aux=aux->next);
    for (int count=0;(aux!=list->last->next && count<pos);count++,aux=aux->next);
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
    //aux->next = listSource->first;
    aux->next = listSource->last->next->next;
    
    listDest->size+=listSource->size;
    
    return listSource->size;
}

void* removePos(LinkedList *list, int pos) {
    if (isEmpty(list) || pos>=list->size) return NULL;
    
    Node *nodeRemove = NULL;
    Node *aux = NULL;
    
    //Se for o primeiro elemento
    //if (pos==0) return dequeue(list);
    
    if (pos==0)
        aux = list->last->next;
    else
        aux = getNodeByPos(list, pos-1);

    //aux = getNodeByPos(list, pos-1);
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
    
//    if (equal(list->first->data,data)) {
//        free(dequeue(list));
//        list->size--;
//        return 1;
//    }
    
//    if (equal(list->last->data,data)) {
//        free(removePos(list, list->size-1));
//        list->size--;
//        return 1;
//    }
    
    //Node *aux = list->first;
    Node *aux = list->last->next; //começo pelo trash
    //while(aux->next!=NULL && !equal(aux->next->data,data))
    while(aux->next!=list->last->next && !equal(aux->next->data,data))
        aux=aux->next;
    
    //if (aux->next!=NULL) {
    if (aux->next!=list->last->next) {
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




