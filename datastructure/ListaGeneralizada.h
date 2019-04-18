//
//  ListaGeneralizada.h
//  datastructure
//
//  Created by João Paulo Delgado Preti on 18/04/19.
//  Copyright © 2019 João Paulo Delgado Preti. All rights reserved.
//

#ifndef ListaGeneralizada_h
#define ListaGeneralizada_h

#include <stdio.h>

typedef struct Node {
    int type; //0 atomo e 1 lista
    union {
        int atom;
        struct Node *list;
    }atomList;
    struct Node *tail;
}Node;

int addAtom(Node **list, int data);
int addList(Node **list, Node **subList);
Node* head(Node *list);
Node* tail(Node *list);
void showGeneralizedList(Node *list);
int height(Node *list);

#endif /* ListaGeneralizada_h */
