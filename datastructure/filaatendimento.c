//
//  filaatendimento.c
//  datastructure
//
//  Created by João Paulo Delgado Preti on 19/06/17.
//  Copyright © 2017 João Paulo Delgado Preti. All rights reserved.
//
/*
 #include "iQueue.h"
 
 #define BOOTHS 3
 
 void initZero(int vector[]) {
	for (int i = 0; i < BOOTHS; i++)
        vector[i] = 0;
 }
 
 int freeBooth(int booths[]) {
	for (int i = 0; i < BOOTHS; i++)
        if (booths[i]==0)
            return i;
	return -1;
 }

 int busyBooth(int booths[]) {
    for (int i = 0; i < BOOTHS; i++)
        if (booths[i]>0)
            return 1;
    return 0;
 }
 
 int main() {
	int booths[BOOTHS], boothsTime[BOOTHS];
	initZero(booths);
	initZero(boothsTime);
	iQueue queue;
	init(&queue,1);
 
	enqueue(&queue,15);
	enqueue(&queue,10);
	enqueue(&queue,5);
	enqueue(&queue,50);
	enqueue(&queue,15);
	enqueue(&queue,25);
	enqueue(&queue,20);
	enqueue(&queue,12);
	enqueue(&queue,18);
	enqueue(&queue,7);
 
	int client=0;
	int queueTime = 0;
 
	while (!isEmpty(&queue) || busyBooth(booths)==1) {
        int booth = freeBooth(booths);
        if (booth >= 0 && !isEmpty(&queue)) {
            printf("Client %d (wait time %d) go to booth %d\n",++client,queueTime,booth+1);
            int clientTime = dequeue(&queue);
            booths[booth] = clientTime;
            boothsTime[booth] += clientTime;
        }
        for (int i = 0; i < BOOTHS; i++)
            if (booths[i] != 0)
                booths[i]--;
        queueTime++;
	}
 
	printf("\n");
 
	for (int i = 0; i < BOOTHS; i++)
        printf("Booth time %d: %d\n",i+1,boothsTime[i]);
 
	return 0;
 }
*/
