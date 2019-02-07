/*
 * InfixaPosfixa.c
 *
 *  Created on: 11 de jun de 2016
 *      Author: joaopaulodelgadopreti
 */
/*
#include "sStack.h"
#include <stdlib.h>
#include <string.h>
 
int in(char *elemento, char elementos[]) {
	for (int i = 0; elementos[i] != 0; i++)
        if (*elemento == elementos[i])
            return 1;
	return 0;
}
 
int prio(char *op) {
	if (*op=='(')             return 1;
	if (*op=='+' || *op=='-') return 2;
	if (*op=='*' || *op=='/') return 3;
	return -1;
}

char* postfix(char *infix) {
	sStack stack;
	init(&stack,1);
	char postfix[100] = "";
	char *word;
	char buffer[10];
 
	word = strtok(infix, " ");
 
	while (word != NULL) {
        if (in(word, "+/-*")) {
            while (!isEmpty(&stack) && prio(top(&stack))>=prio(word)){
                strcat(postfix, pop(&stack));
                strcat(postfix, " ");
            }
            push(&stack, word);
        } else if (word[0] == '(') {  //(2 * 3 + 5) * 4
            //empilha o parenteses	saida= 2 3 * 5 + 4 *
            push(&stack, "(");	//	pilha=
            //concatena na saída o número
            memcpy(buffer, &word[1], strlen(word) - 1);
            strcat(postfix, buffer);
            memset(buffer, 0, sizeof buffer); //clean the buffer
            strcat(postfix, " ");
        } else if (word[strlen(word) - 1] == ')') {
            memcpy(buffer, &word[0], strlen(word) - 1);
            strcat(postfix, buffer);
            memset(buffer, 0, sizeof buffer); //clean the buffer
            strcat(postfix, " ");
            while (strcmp(top(&stack),"(")!=0){
                strcat(postfix, pop(&stack));
                strcat(postfix, " ");
            }
            //descarta o parenteses
            pop(&stack);
        } else {
            //concatena na saída o número
            strcat(postfix, word);
            strcat(postfix, " ");
        }
        word = strtok( NULL, " ");
	}
	while (!isEmpty(&stack)) {
        strcat(postfix, pop(&stack));
        strcat(postfix, " ");
	}
 
	return postfix;
}

int main() {
	char infix[] = "11 + 2233 * (3344 + 44)";
	printf("%s\n",postfix(infix));
	return EXIT_SUCCESS;
}
*/
