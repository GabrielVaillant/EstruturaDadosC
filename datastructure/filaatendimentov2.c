/*
 * filaatendimentov2.c
 *
 *  Created on: 5 de jul de 2017
 *      Author: joaopaulodelgadopreti
 */
/*
#include "clientQueue.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>
 
#define BOOTHS 3
#define BANK_CLOSE_TIME 10000
 
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
 
int main() {
	int booths[BOOTHS], boothsTime[BOOTHS];
	initZero(booths);
	initZero(boothsTime);
	regClientQueue queue;
	init(&queue,1);
 
	enqueue(&queue,(regClient){1,0,15});
	enqueue(&queue,(regClient){2,0,10});
	enqueue(&queue,(regClient){3,0,5});
	enqueue(&queue,(regClient){4,0,6});
	enqueue(&queue,(regClient){5,0,15});
	enqueue(&queue,(regClient){6,0,11});
	enqueue(&queue,(regClient){7,0,9});
	enqueue(&queue,(regClient){8,0,8});
	enqueue(&queue,(regClient){9,0,12});
	enqueue(&queue,(regClient){10,0,7});
 
	int clientCount=10;//we already have 10 clients in the queue
	int queueTime = 0; //the first 10 clients arrived when the bank agency opened.
	int maxWaitTime = 0;
	int totalWaitTime = 0;
 
	while (!isEmpty(&queue) || queueTime < BANK_CLOSE_TIME) {
        srand((unsigned)time(NULL));
        if (queueTime%((rand()%25))==0 && queueTime < BANK_CLOSE_TIME) { // it is possible to enter in the queue only in working time.
            srand((unsigned)time(NULL));
            int time = (rand()%70);
            enqueue(&queue,(regClient){++clientCount,queueTime,time});
        }
 
        int booth = freeBooth(booths);
        if (booth >= 0 && !isEmpty(&queue)) {
            regClient client = dequeue(&queue);
            int waitTime = queueTime-client.arrivalTime;
            printf("Client %d (wait time %d) go to booth %d\n",client.id,waitTime,booth+1);
            booths[booth]= client.workTime;
            boothsTime[booth] += client.workTime;
            if (waitTime>maxWaitTime) maxWaitTime = waitTime;
            totalWaitTime+=waitTime;
        }
        
        for (int i = 0; i < BOOTHS; i++)
            if (booths[i]!=0)
                booths[i]--;
            queueTime++;
    }
 
	printf("\n");
 
	for (int i = 0; i < BOOTHS; i++)
        printf("Time of the booth %d: %d\n",i+1,boothsTime[i]);
 
	printf("\n");
 
	printf("Average wait time: %d\n",totalWaitTime/clientCount);
	printf("Maximum wait time: %d\n",maxWaitTime);
	return 0;
}
*/
