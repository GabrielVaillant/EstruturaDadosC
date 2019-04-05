#include <stdio.h>
#include <stdlib.h>
#include "Hash.h"

typedef struct Cliente {
    char nome[50];
    char email[50];
}Cliente;

bool comparaChaves(void *key, void *data) {
    char *chave = (char*)key;
    Cliente *c = (Cliente*)data;
    
    return (strcmp (chave, c->nome) == 0)?true:false;
}

void initHash(HashStruct *hashStruct) {
    for (int i=0;i<MAX;i++) {
        init(&(hashStruct->hashes[i]));
    }
    hashStruct->size = 0;
}

bool IsHashEmpty(HashStruct *hashStruct) {
    return hashStruct->size==0;
}

int hash(char *key) {
    int sum = 0;
    for (int i = 0; key[i]!=0;i++) {
        sum+=key[i]*(i+1);
    }
    return sum%MAX;
}

int put(HashStruct *hashStruct, char *key, void *data)  {
    int res = enqueue(&hashStruct->hashes[hash(key)],data);
    hashStruct->size+=res;
    return res;
}

bool containsKey(HashStruct *hashStruct, char *key, compare equal) {
    int hashValue = hash(key);
    int pos = indexOf(&hashStruct->hashes[hashValue], key, comparaChaves);
    
    return (pos!=-1)?true:false;
}

void* get(HashStruct *hashStruct, char *key, compare equal) {
    int hashValue = hash(key);
    int pos = indexOf(&hashStruct->hashes[hashValue], key, comparaChaves);
    return getPos(&hashStruct->hashes[hashValue], pos);
}

void* removeKey(HashStruct *hashStruct, char *key, compare equal) {
    return NULL;
}

void showHashStruct(HashStruct *hashStruct) {
    printf("There are %d elements in the Hash\n\n",hashStruct->size);
    for (int i=0; i < MAX; i++) {
        printf("Hash %d has %d elements: ",i,hashStruct->hashes[i].size);
        show(&hashStruct->hashes[i]);
        printf("\n");
    }
}

int main() {
    HashStruct hashes;
    initHash(&hashes);
    printf("%d\n",hash("Joao"));
    int *aux = (int *)malloc(sizeof(int));
    *aux=1;
    put(&hashes, "Joao", aux);

    Cliente *c = (Cliente *)malloc(sizeof(Cliente));
    strcpy(c->nome,"Joao Paulo") ;
    strcpy(c->email,"joao.preti@cba.ifmt.edu.br");
    printf("%d\n",hash(c->nome));
    put(&hashes, c->nome, c);
    printf("%d\n",hashes.hashes[1].size);
    printf("%d\n",hashes.size);
    printf("%d\n",containsKey(&hashes, "Joao Paulo", comparaChaves));
    
    Cliente *cliente = (Cliente*)get(&hashes, "Joao Paulo", comparaChaves);
    printf("%s\n",cliente->email);
    
    showHashStruct(&hashes);
    return 0;
}
