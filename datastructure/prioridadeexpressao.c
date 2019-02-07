/******************************************************************
 * Programa prioridadeexpressao.c
 * Verificando a corretude na prioridade das expressões com pilha
 * Autor: João Paulo D. Preti
 *******************************************************************/
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cStack.h"
 
int in(char element, char elements[]) {
	for (int i = 0; elements[i]!=0; i++)
        if (element == elements[i])
            return i;
	return -1;
}
 
long evaluateOpenClose(char expression[], char charsOpen[], char charsClose[]) {
	cStack stack;
	init(&stack,1);
 
	for (int i = 0 ; expression[i] != 0 ; i++) {
        if (in(expression[i],charsOpen)>=0)
            push(&stack,expression[i]);
 
        if (in(expression[i],charsClose)>=0) {
            if (!isEmpty(&stack)) {
                if (in(pop(&stack),charsOpen) == in(expression[i],charsClose)) {
                    //Do nothing, pop already executed.
                } else {
                    return i;
                }
            } else {
                return i;
            }
        }
	}
    if (!isEmpty(&stack)) return strlen(expression); //poderia usar uma pilha de inteiros para guardar a posicao dos caracteres de abertura para entao apontar qual a posicao do caractere que sobrou
	return -1;
}
 
char* fillWhiteSpaceBefore(long qttySpaces, char c) {
	char *text = (char *) malloc(sizeof(char) * qttySpaces);
	for (int i = 0 ; i < qttySpaces-2 ; i++)
        text[i] = ' ';
	text[qttySpaces-2] = c;
	text[qttySpaces-1] = '\0';
	return text;
}

int main() {
 
	char expression[] = "41 . 30 : {23 . [52 – 23 . )(4 - 3) - (3 . 5)]} : 5";
 
	long result = evaluateOpenClose(expression, "{[(","}])");
 
	if (result>=0) {
        printf("Invalid Expression!\n");
        printf("%s\n",expression);
        printf("%s\n",fillWhiteSpaceBefore(result, '^'));
	} else
        printf("Valid Expression!\n");
 
	return EXIT_SUCCESS;
}
*/
