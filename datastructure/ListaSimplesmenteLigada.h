//
//  ListaSimplesmenteLigada.h
//  EstruturaDeDados
//
//  Created by João Paulo Delgado Preti on 11/12/14.
//  Copyright (c) 2014 João Paulo Delgado Preti. All rights reserved.
//

#ifndef EstruturaDeDados_ListaSimplesmenteLigada_h
#define EstruturaDeDados_ListaSimplesmenteLigada_h

typedef struct No {
    int dado;
    struct No *prox;
}No;

typedef struct ListaSimplesmenteLigada {
    No *inicio;
    int tamanho;
}ListaSimplesmenteLigada;

void inicializa(ListaSimplesmenteLigada *lista);
int inserirInicio(ListaSimplesmenteLigada *lista, int dado);
int inserirFinal(ListaSimplesmenteLigada *lista, int dado);
int inserir(ListaSimplesmenteLigada *lista, int posicao, int dado);
int removerPorDado(ListaSimplesmenteLigada *lista, int dado);
int removerPorPosicao(ListaSimplesmenteLigada *lista, int posicao);
int buscarPorPosicao(ListaSimplesmenteLigada *lista, int posicao);
int buscarPorDado(ListaSimplesmenteLigada *lista, int dado);

#endif
