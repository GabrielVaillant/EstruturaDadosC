//
//  process_scheduler.c
//  datastructure
//
//  Created by João Paulo Delgado Preti on 19/07/17.
//  Copyright © 2017 João Paulo Delgado Preti. All rights reserved.
//
/*
#include <stdio.h>
#include "processQueue.h"

#define CPUS 2

typedef struct cpu {
    int id;
    int timeSharing;
    process process;
}cpu;

int anyProcessExecuting(cpu cpus[]) {
    for (int i = 0; i < CPUS; i++) {
        if (cpus[i].process.processedTime<cpus[i].process.workingTime)
            return 1;
    }
    return 0;
}

void allocateProcess(cpu *cpu, processQueue *queue, processQueue *history) {
    if (cpu->process.processedTime < cpu->process.workingTime) {
        enqueue(queue,cpu->process);
    } else {
        if (cpu->process.id>0) enqueue(history,cpu->process); // sem a condição a primeira chamada ao procedimento tenta jogar no historico o processo que esta na cpu, mas nao tem ninguem antes do primeiro processo alocado
        cpu->process.id=0; //para garantir que ao final do programa as cpus sem processo em execução estejam com p.id=0
    }
    cpu->process = dequeue(queue);
    cpu->process.numberOfAllocations++;
}

void initCPUS(cpu cpus[]) {
    for (int i = 0; i < CPUS; i++) {
        cpus[i].id = i;
        cpus[i].timeSharing = (i*10)+10;
    }
}

int main() {
    processQueue queue,history; //a primeira fila representa os processos em estado de pronto para execução e a segunda os processos que foram finalizados
    init(&queue,1);
    init(&history,2);
    
    enqueue(&queue,(process){1,15,0,0});
    enqueue(&queue,(process){2,20,0,0});
    enqueue(&queue,(process){3,10,0,0});
    enqueue(&queue,(process){4,30,0,0});
    enqueue(&queue,(process){5,35,0,0});
    enqueue(&queue,(process){6,25,0,0});
    enqueue(&queue,(process){7,50,0,0});
    enqueue(&queue,(process){8,05,0,0});
    enqueue(&queue,(process){9,20,0,0});
    
    cpu cpus[CPUS];
    initCPUS(cpus);
    
    int time=0;
    
    while (!isEmpty(&queue) || anyProcessExecuting(cpus)) {
        
        for (int i = 0; i < CPUS; i++) {
            if ((time%cpus[i].timeSharing)==0 && !isEmpty(&queue)) {
                printf("CPU %d:\tPID: %d\t TIME: %d\n",i+1,peek(&queue).id,time);
                allocateProcess(&cpus[i],&queue,&history);
            }
            
            cpus[i].process.processedTime++;
        }
        
        time++;
    }
    
    //serve para tirar o ultimo processo em execução no processador e guardar no historico
    for (int i = 0; i < CPUS; i++)
        if (cpus[i].process.id>0)
            enqueue(&history,cpus[i].process);
    
    printf("Processing total time: %d\n",time);
    printf("\n\n");
    
    while (!isEmpty(&history)) {
        process p = dequeue(&history);
        printf("PID: %d\tNum. of Allocations: %d\tSpended time: %d\t\tIdle time :%d\n",p.id,p.numberOfAllocations,p.processedTime, p.processedTime-p.workingTime);
    }
    
    return 0;
 
}*/
