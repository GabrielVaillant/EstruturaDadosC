//
//  BinarySearchTree.h
//  datastructure
//
//  Created by João Paulo Delgado Preti on 19/04/19.
//  Copyright © 2019 João Paulo Delgado Preti. All rights reserved.
//

#ifndef BinarySearchTree_h
#define BinarySearchTree_h

#include <stdlib.h>
#include <stdio.h>

typedef struct TreeNode {
    void *element;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

/*
 * O usuário da bilbioteca deve fornecer uma função para comparação dos elementos
 */
typedef int (*TreeComparator)(void *element1, void *element2);

/*
 * Adiciona um novo elemento na árvore
 *
 * Argumentos:
 * - root:    A raiz da árvore/subárvore
 * - element: o elemento a ser adicionado
 * - f: a função para comparação dos elementos
 * - newroot: um parâmetro que guarda o endereço de memório do ponteiro da raiz da árvore/subárvore.
 *
 * Retorna:
 * - 1 em caso de sucesso
 * - 0 caso não tenha mais memória
 * - -1 caso o elemento já exista na árvore
 */
int add(TreeNode *root, void *element, TreeComparator f, TreeNode **newroot);

/*
 * Localiza um elemento na árvore
 *
 * Argumentos:
 * - root:    A raiz da árvore/subárvore
 * - key: o elemento a ser localizado
 * - f: a função para comparação dos elementos
 * - element: um parâmetro de saída
 *
 * Retorna:
 * - 1 em caso de sucesso
 * - 0 caso não encontre
 */
int find(TreeNode *root, void *key, TreeComparator f, void **element);

#endif /* BinarySearchTree_h */
