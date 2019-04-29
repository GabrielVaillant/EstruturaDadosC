//
//  Blockchain.h
//  datastructure
//
//  Created by João Paulo Delgado Preti on 19/04/19.
//  Copyright © 2019 João Paulo Delgado Preti. All rights reserved.
//
//  Está implementado somente o conceito de blockchain, para o conceito
//  de criptoativo falta implementar o conceito de Proof-of-Work (puzzle),
//  Transações, Carteira (wallet) e Comunicação e sincronização entre os nós.
//

#ifndef Blockchain_h
#define Blockchain_h

#include <stdlib.h>
#include <stdio.h>

enum boolean {
    true = 1, false = 0
};

typedef enum boolean bool;

typedef struct Block {
    unsigned int index;
    char* previousHash;
    struct Block* previousBlock;
    unsigned long timestamp;
    float data;
    char* hash;
}Block;

typedef struct Blockchain {
    Block *genesisBlock;
    Block *latestBlock;
}Blockchain;

void initBlockchain(Blockchain *blockchain);
char* calculateHash(int index, char* previousHash, unsigned long timestamp, float data);
Block* generateNextBlock(Blockchain *blockchain, float data);
Block* getLatestBlock(Blockchain *blockchain);
bool isValidNewBlock(Block* newBlock, Block* previousBlock);
bool isBlockchainValid(Blockchain *blockchain);
int addBlock(Blockchain *blockchain, Block *newBlock);

#endif /* Blockchain_h */

