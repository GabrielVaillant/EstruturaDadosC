//
//
//  EstruturaDeDados
//
//  Created by João Paulo Delgado Preti.
//  Copyright (c) 2014 João Paulo Delgado Preti. All rights reserved.
//

#ifndef EstruturaDeDados_List_h
#define EstruturaDeDados_List_h

enum boolean { true = 1, false = 0 };

typedef enum boolean bool;

typedef struct SNode { void *data; struct SNode *next; }SNode;

typedef struct DNode { void *data; struct DNode *previous; struct DNode *next; }DNode;

typedef struct SList { SNode *last; int size; }SList;

typedef struct DList { DNode *first; int size; }DList;

typedef bool (*compare)(void*,void*);

void init(SList *list);                             // 1 Ponto
bool isEmpty(SList *list);                          // 1 Ponto
int add(SList *list, int pos, void *data);          // 2 Pontos
void* removePos(SList *list, int pos);              // 2 Pontos
int indexOf(SList *list,void *data, compare equal); // 2 Pontos
DList* convertSList(SList *list);                   // 2 Pontos

#endif


