#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "iQueue.h"
#define PROCESSOS 9


/*
int main(){
    int EXECUTADOR[PROCESSOS],TEMPO[PROCESSOS],cont=1,tempoTotal=0,i,maiorGasto=0;
    
    iQueue fila;
    init(&fila,1);
    
    enqueue(&fila,10);
    enqueue(&fila,115);
    enqueue(&fila,20);
    
    enqueue(&fila,8);
    enqueue(&fila,15);
    enqueue(&fila,5);
    enqueue(&fila,10);
    enqueue(&fila,5);
    
    enqueue(&fila,40);
    
    for(i=0;i<PROCESSOS;i++){
        EXECUTADOR[i] = 0;
        TEMPO[i] = 0;
    }
    
    while(!isEmpty(&fila)){ // enquanto a fila nao estiver vazia
        for(i=0;i<PROCESSOS;i++){	// percorrendo o vetor de processos
            if(EXECUTADOR[i] > 0)		// se o executador estiver em andamento
                EXECUTADOR[i]--;	// decrementar para executar o processso seguinte
        }
    }
    
    tempoTotal++; // variavel que ira cronometrar o tempo total gasto na CPU
    
    
    for(i=0;i<PROCESSOS;i++){
        if(EXECUTADOR[i] == 0){ // nao ha nenhum processo em execucao
            printf("\nPROCESSO [%d] move para [%d]",cont++,i);
            dequeue(&fila);
            TEMPO[i] += EXECUTADOR[i];
            if(TEMPO[i] > maiorGasto)
                maiorGasto = TEMPO[i];
            if(isEmpty(&fila))
                break;
        }
    }
    
    
    printf("\nO TEMPO TOTAL GASTO NA CPU : [%d]",tempoTotal);
    
    
    return (EXIT_SUCCESS);
}
*/
