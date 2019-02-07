/******************************************************************
 * Programa torrehanoi.c	                                              *
 *                                                                        *
 * Demonstracão do uso de pilha para resolver o problema da torre de hanoi*
 * Data: 30/05/2016			                                              *
 * Autor: João Paulo D. Preti                                             *
 **************************************************************************/
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "iStack.h"
 
void movedisc(int num, iStack *from, iStack *to, iStack *aux) {
	
	if (num == 1) {
        push(to,pop(from));
        printf("Moving disc %d from %d to %d\n", top(to), from->id, to->id);
	} else {
        movedisc(num-1,from, aux, to);
        push(to,pop(from));
        printf("Moving disc %d from %d to %d\n", top(to), from->id, to->id);
        movedisc(num-1, aux, to, from);
	}
}
 
int main() {
	iStack towers[3];
 
	init(&towers[0],1);
	init(&towers[1],2);
	init(&towers[2],3);
 
	push(&towers[0], 3);
	push(&towers[0], 2);
	push(&towers[0], 1);
 
	movedisc(size(&towers[0]), &towers[0], &towers[2], &towers[1]);
    show(&towers[2]);
    return EXIT_SUCCESS;
}
*/



