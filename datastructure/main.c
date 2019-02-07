//
//  main.c
//  datastructure
//
//  Created by João Paulo Delgado Preti on 26/03/17.
//  Copyright © 2017 João Paulo Delgado Preti. All rights reserved.
//
/*
#include <stdio.h>

#define SIZE 5

enum boolean {
    true = 1, false = 0
};

typedef enum boolean bool;

int main(int argc, const char * argv[]) {
    int vetor[SIZE] = {5,4,3,2,1};
    
    for (int i = 0; i < SIZE-1; i++) {
        for (int j = i+1; j < SIZE; j++) {
            if (vetor[i] > vetor[j]) {
                int aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
    
    for (int i = 0; i < SIZE; i++)
        printf("%d ",vetor[i]);
    
    int inicio=0,fim = SIZE-1, chave = 5;
    
    bool achou = false;
    
    while (inicio<=fim && !achou) {
        int meio = (inicio+fim)/2;
        if (chave == vetor[meio]) {
            achou = true;
            printf("\n\nEncontrado na posicao %d\n\n",meio);
        } else {
            if (chave < vetor[meio])
                fim = meio - 1;
            else
                inicio = meio + 1;
        }
    }
    
    if (!achou) printf("\n\nValor não encontrado!\n\n");
    
    return 0;
}
 */
