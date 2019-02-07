/**************************************************************************
 * Programa validararquivo.c	                                          *
 *                                                                        *
 * Demonstracão do uso de pilha para ler um arquivo C e apontar a linha   *
 * com problemas de fechamento de parênteses ou chaves 					  *
 * Data: 30/05/2016			                                              *
 * Autor: João Paulo D. Preti                                             *
 **************************************************************************/
/*
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include "cStack.h"
 
 const int BUFFER_SIZE = 300; // how many chars will be read at a time
 const int MAX_SIZE = 30000; // maximum chars allowed
 
int in(char element, char elements[]) {
	for (int i = 0; elements[i] != 0; i++)
        if (element == elements[i])
            return i;
	return -1;
}
 
long evaluateOpenClose(char expression[], char charsOpen[], char charsClose[]) {
	cStack stack;
	init(&stack,1);
 
	for (int i = 0; expression[i] != 0; i++) {
        if (in(expression[i], charsOpen) >= 0)
            push(&stack, expression[i]);
 
        if (in(expression[i], charsClose) >= 0) {
            if (!isEmpty(&stack)) {
                if (in(pop(&stack), charsOpen) == in(expression[i],charsClose)) {
                    //Do nothing, pop already executed.
                } else {
                    return i;
                }
            } else {
                return i;
            }
        }
	}
    if (!isEmpty(&stack)) return strlen(expression);
	return -1;
}

int main(int argc, char *argv[]) {
	FILE *file = fopen("/Users/joaopaulodelgadopreti/XCodeGIT/datastructure/datastructure/palindroma.c", "r");
	char buffer[BUFFER_SIZE];
	char fullText[MAX_SIZE];
 
	if (file != NULL) {
        int line = 1;
        while (fgets(buffer, BUFFER_SIZE, file)) {
            strcat(fullText,buffer);
            printf("%d: %s\n", line, buffer);
            line++;
        }
 
        long result = evaluateOpenClose(fullText, "{[(", "}])");
 
        if (result >= 0) {
            int errorLine = 1;
            for (int i = 0; i < result; i++)
                if (fullText[i]=='\n')
                    errorLine++;
 
            printf("Error in line: %d\n", errorLine);
        }
 
        fclose(file);
    } else
        printf("File not found or not possible to open!");
 
    printf("\n\n");
	return 0;
}
 
*/



























/*
 //copiaVetor(buffer, textoCompleto, (linha - 1) * 300, 300);
 //int tamanhoArquivo = ftell(arquivo);
 //for (int i = 0; i < tamanhoArquivo; i++) printf("%c",textoCompleto[i]);
 
 void copiaVetor(char vetorOrigem[], char vetorDestino[], int posInicial,
 int tamanho) {
	for (int i = 0; i < tamanho; i++)
 vetorDestino[posInicial + i] = vetorOrigem[i];
 }
 */














