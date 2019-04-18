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

typedef struct No {
    int tipo; //0 atomo e 1 lista
    union {
        int atomo;
        struct No *lista;
    }atomList;
    struct No *prox;
}No;

int inserirAtomo(No **lista, int dado);
int inserirLista(No **lista, No **subLista);
No* cabeca(No *lista);
No* cauda(No *lista);
void print(No *lista);
int profundidade(No *lista);
#endif /* ListaGeneralizada_h */
