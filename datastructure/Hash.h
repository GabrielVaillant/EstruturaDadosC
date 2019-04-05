//
//
//  EstruturaDeDados
//
//  Created by João Paulo Delgado Preti.
//  Copyright (c) 2014 João Paulo Delgado Preti. All rights reserved.
//

#ifndef EstruturaDeDados_Hash_h
#define EstruturaDeDados_Hash_h

#include "DoublyLinkedList.h"

#define MAX 10

typedef struct HashStruct {
    DoublyLinkedList hashes[MAX];
    int size;
}HashStruct;

void initHash(HashStruct *hashStruct);
bool IsHashEmpty(HashStruct *hashStruct);
int hash(char *key);
int put(HashStruct *hashStruct, char *key, void *data);
bool containsKey(HashStruct *hashStruct, char *key, compare equal);
void* get(HashStruct *hashStruct, char *key, compare equal);
void* removeKey(HashStruct *hashStruct, char *key, compare equal);

#endif

