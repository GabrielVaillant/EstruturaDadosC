//
//  compilador.c
//  datastructure
//
//  Created by João Paulo Delgado Preti on 19/06/17.
//  Copyright © 2017 João Paulo Delgado Preti. All rights reserved.
//
/*
#include <string.h>
#include "iStack.h"

void getInstruction(char* instruction, char* line) {
    strcpy(instruction, line);
    strtok(instruction," ");
}

char* getParameter(char* line) {
    char* aux = strtok(line," ");
    aux = strtok(NULL," ");
    return aux;
}

int getRoutinePosition(char* lines[100], char *routine) {
    char _routine[50] = "routine ";
    strcat(_routine, routine);
    for (int i = 0; i < 100; i++) {
        if (strcmp(lines[i],_routine)==0)
            return i;
    }
    
    return -1;
}

void print(char* line) {
    char lineAux[100];
    strcpy(lineAux, line);
    printf("%s\n",getParameter(lineAux));
}

int main() {
    char programSource[250]="routine A\nprint \"1\"\ncall B\ncall C\nreturn\nroutine B\ncall C\nprint \"3\"\nreturn\nroutine C\nprint \"2\"\nreturn";
    
    char* line = strtok(programSource,"\n");
    char* lines[100];
    int linesProgram = 0;
    while (line!=NULL) {
        lines[linesProgram++] = line;
        line = strtok(NULL, "\n");
    }
    
    iStack executionStack;
    init(&executionStack,1);
    int instructionCounter=0;
    char instruction[50];
    int end = 0;
    while (!end) {
        //printf("%d\n",contadorInstrucao+1);
        char* executionLine = lines[instructionCounter];
        instructionCounter++;
        getInstruction(instruction, executionLine);
        if (strcmp(instruction,"return")==0 && isEmpty(&executionStack))
            end=1;

        if (strcmp(instruction,"routine")==0)
            continue;
        
        if (strcmp(instruction,"print")==0) {
            print(executionLine);
            continue;
        }
        if (strcmp(instruction,"return")==0 && !isEmpty(&executionStack)) {
            instructionCounter = pop(&executionStack);
            continue;
        }
        if (strcmp(instruction,"call")==0) {
            push(&executionStack,instructionCounter);
            instructionCounter=getRoutinePosition(lines, getParameter(executionLine));
            continue;
        }
    }
    
    return 0;
}
 */
