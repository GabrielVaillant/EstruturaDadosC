//
//  colorindo.c
//  datastructure
//
//  Created by João Paulo Delgado Preti on 04/08/17.
//  Copyright © 2017 João Paulo Delgado Preti. All rights reserved.
//
/*
#include "xyQueue.h"

void colorir(int img[6][6], int x, int y, int novaCor) {
    int corOriginal=img[x][y];
    xyQueue coordenadas;
    init(&coordenadas,1);
    enqueue(&coordenadas,(coordXY){x,y});
    
    while (!isEmpty(&coordenadas)) {
        coordXY pos = dequeue(&coordenadas);
        if (img[pos.x+1][pos.y]==corOriginal) enqueue(&coordenadas,(coordXY){pos.x+1,pos.y});
        if (img[pos.x][pos.y-1]==corOriginal) enqueue(&coordenadas,(coordXY){pos.x,pos.y-1});
        if (img[pos.x-1][pos.y]==corOriginal) enqueue(&coordenadas,(coordXY){pos.x-1,pos.y});
        if (img[pos.x][pos.y+1]==corOriginal) enqueue(&coordenadas,(coordXY){pos.x,pos.y+1});
        img[pos.x][pos.y] = novaCor;
    }
}

int main() {
    int imagem[6][6] = {
        {176, 177, 178, 178, 178, 176},
        {176, 177, 177, 176, 176, 178},
        {176, 177, 177, 177, 177, 178},
        {176, 177, 177, 176, 177, 178},
        {177, 176, 177, 176, 176, 176},
        {176, 177, 176, 176, 176, 176}
    };
    
    int i,j;
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 6; j++) {
            printf("%d ",imagem[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");
    
    colorir(imagem, 0, 1, 999);
    
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 6; j++) {
            printf("%d ",imagem[i][j]);
        }
        printf("\n");
    }
}
 */
