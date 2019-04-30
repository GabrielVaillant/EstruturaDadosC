//
//  Blockchain.c
//  datastructure
//
//  Created by João Paulo Delgado Preti on 19/04/19.
//  Copyright © 2019 João Paulo Delgado Preti. All rights reserved.
//

#include "Blockchain.h"
#include <string.h>
#include "sha-256.h"
#include <time.h>

void initBlockchain(Blockchain *blockchain) {
    Block *genesisBlock = malloc(sizeof(Block));
    genesisBlock->index = 0;
    genesisBlock->previousHash = "0";
    genesisBlock->previousBlock = NULL;
    genesisBlock->timestamp = time(NULL);
    genesisBlock->data = 1000000;
    
    genesisBlock->hash = calculateHash(genesisBlock->index, genesisBlock->previousHash, genesisBlock->timestamp, genesisBlock->data);
    //"816534932c2b7154836da6afc367695e6337db8a921823784c14378abed4f7d7";
    blockchain->genesisBlock = genesisBlock;
    blockchain->latestBlock = genesisBlock;
}

static void hash_to_string(char string[65], const uint8_t hash[32])
{
    size_t i;
    for (i = 0; i < 32; i++) {
        //montar uma string com 64 caracteres hexadecimais
        string += sprintf(string, "%02x", hash[i]); //02x hexadecimal em 2 caracteres
    }
}

char* calculateHash(int index, char* previousHash, unsigned long timestamp, float data) {
    char input[1024];
    sprintf(input, "%i%s%lu%.8f",index,previousHash, timestamp, data);

    uint8_t hash[32]; //vetor de 32 bytes de inteiros unsigned [0-255] (256/8 = 32)
    //char hash_string[65];
    char *hash_string = malloc(sizeof(char)*65);
    calc_sha_256(hash, input, strlen(input));
    hash_to_string(hash_string, hash);

    return hash_string;
}

char* calculateBlockHash(Block *block) {
    return calculateHash(block->index, block->previousHash, block->timestamp, block->data);
}

Block* generateNextBlock(Blockchain *blockchain, float data) {
    Block *previousBlock = getLatestBlock(blockchain);
    Block *newBlock = malloc(sizeof(Block));
    
    newBlock->data = data;
    newBlock->previousHash = previousBlock->hash;
    newBlock->index = previousBlock->index+1;
    newBlock->timestamp = time(NULL);
    newBlock->hash = calculateBlockHash(newBlock);
    
    return newBlock;
}

Block* getLatestBlock(Blockchain *blockchain) {
    return blockchain->latestBlock;
}

bool isValidNewBlock(Block* newBlock, Block* previousBlock) {
    if (previousBlock->index + 1 != newBlock->index) {
        return false;
    } else if (previousBlock->hash != newBlock->previousHash) {
        return false;
    } else if (strcmp(calculateBlockHash(newBlock),newBlock->hash)!=0) {
        return false;
    }
    return true;
}

bool isBlockchainValid(Blockchain *blockchain) {
    Block *aux = getLatestBlock(blockchain);
    while (aux!=blockchain->genesisBlock) {
        if (!isValidNewBlock(aux, aux->previousBlock))
            return false;
        aux = aux->previousBlock;
    }
    return true;
}

int addBlock(Blockchain *blockchain, Block *newBlock) {
    if (isValidNewBlock(newBlock, getLatestBlock(blockchain))) {
        newBlock->previousBlock = getLatestBlock(blockchain);
        blockchain->latestBlock = newBlock;
        return 1;
    }
    return -1;
}

int main() {
    Blockchain blockchain;
    printf("");
    initBlockchain(&blockchain);

    printf("%s\n",blockchain.genesisBlock->hash);
    printf("%lu\n",blockchain.genesisBlock->timestamp);
    
    Block *newBlock2 = generateNextBlock(&blockchain,80.0);
    addBlock(&blockchain, newBlock2);
    
    Block *newBlock3 = generateNextBlock(&blockchain,250.0);
    addBlock(&blockchain, newBlock3);
    
    printf("Block 2 is valid? %i\n",isValidNewBlock(newBlock2, blockchain.genesisBlock));
    
    printf("Blockchain is valid? %i\n",isBlockchainValid(&blockchain));
    printf("size: %u\n",blockchain.latestBlock->index);
    return 0;
}

