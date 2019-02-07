/*#include <stdio.h>
#include <stdlib.h>
#include "ListaSimplesmenteLigada.h"

void inicializa(ListaSimplesmenteLigada *lista) {
	lista->inicio = NULL;
	lista->tamanho = 0;
}

int inserirInicio(ListaSimplesmenteLigada *lista, int dado) {
	No *novoNo = (No*) malloc(sizeof(No));
	if (novoNo==NULL) return -1;
	novoNo->dado = dado;
	novoNo->prox = lista->inicio;
	lista->inicio = novoNo;
	lista->tamanho++;
	return 1;
}

int inserirFinal(ListaSimplesmenteLigada *lista, int dado) {
	No *novoNo = (No*) malloc(sizeof(No));
	if (novoNo==NULL) return -1;
	novoNo->dado = dado;
	novoNo->prox = NULL;
	if (lista->tamanho==0) {
		return inserirInicio(lista, dado);
	}
	No *aux = lista->inicio;
	while(aux->prox!=NULL) {
		aux = aux->prox;
	}
	aux->prox = novoNo;
	lista->tamanho++;
	return 1;
}

int inserir(ListaSimplesmenteLigada *lista, int posicao, int dado) {
	No *novoNo = (No*) malloc(sizeof(No));
	if (novoNo==NULL) return -1;
	novoNo->dado = dado;
	novoNo->prox = NULL;
	if (posicao==0) {
		return inserirInicio(lista, dado);
	}
	if (posicao>=lista->tamanho) {
		return inserirFinal(lista, dado);
	}

	int count = 0;
	No *aux = lista->inicio;
	while (count < posicao-1) {
		aux = aux->prox;
		count++;
	}
	novoNo->prox = aux->prox;
	aux->prox = novoNo;
	lista->tamanho++;

	return 1;
}

int removerPorDado(ListaSimplesmenteLigada *lista, int dado) {
	No *aux;
	aux = lista->inicio;
	if (lista->inicio->dado==dado) {
		lista->inicio = lista->inicio->prox;
		lista->tamanho--;
		free(aux);
		return 1;
	} else {
		for (aux = lista->inicio; aux!=NULL && aux->prox->dado!=dado ; aux=aux->prox);
		if (aux==NULL) return 0;
		No *remover = aux->prox;
		aux->prox = aux->prox->prox;
		lista->tamanho--;
		free(remover);
		return 1;
	}
}

int buscarPorDado(ListaSimplesmenteLigada *lista, int dado) {
	No *aux;
	int count;
	for (aux = lista->inicio, count = 0; aux!=NULL; aux = aux->prox, count++) {
		if (aux->dado == dado) return count;
	}
	return -1;
}

int main() {
	ListaSimplesmenteLigada lista;
	inicializa(&lista);
	inserirInicio(&lista, 1);
	inserirInicio(&lista, 2);
	inserirInicio(&lista, 3);
	inserir(&lista,2,10);
	No *aux = lista.inicio;
	printf("%d\n", removerPorDado(&lista, 2));
	while (aux!=NULL) {
		printf("%d\n", aux->dado);
		aux = aux->prox;
	}

	return 0;
}*/




