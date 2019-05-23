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
 * O usuário da bilbioteca deve fornecer uma função para impressão dos dados do TreeNode
 */
typedef void (*printNode)(void*);

/*
 * Adiciona um novo elemento na árvore
 *
 * Argumentos:
 * - root:    O endereço do ponteiro da raiz da árvore/subárvore
 * - element: o elemento a ser adicionado
 * - f: a função para comparação dos elementos
 
 *
 * Retorna:
 * - 1 em caso de sucesso
 * - 0 caso não tenha mais memória
 * - -1 caso o elemento já exista na árvore
 */
int add(TreeNode **root, void *element, TreeComparator f);

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

/*
 * Imprime os elementos ERD
 */
void in_order(TreeNode *root, printNode print);

/*
 * Imprime os elementos RED
 */
void pre_order(TreeNode *root, printNode print);

/*
 * Imprime os elementos EDR
 */
void post_order(TreeNode *root, printNode print);

/*
 * Remove um elemento na árvore
 *
 * Argumentos:
 * - root:    A raiz da árvore/subárvore
 * - key: o elemento a ser localizado e removido
 * - f: a função para comparação dos elementos
 *
 * Retorna:
 * - 1 em caso de sucesso
 * - 0 caso não encontre
 */
int removeTreeNode(TreeNode **root, void *key, TreeComparator f);

/*
 * Calcula a altura da árvore/subárvore
 *
 * Argumentos:
 * - root: A raiz da árvore/subárvore
 *
 * Retorna:
 * - inteiro que representa a altura da árvore
 * - árvore com apenas um nó tem altura 0
 */
int height (TreeNode *root);

/*
 * Destrói a árvore/subárvore
 *
 * Argumentos:
 * - root: A raiz da árvore/subárvore
 */
void destroy (TreeNode **root);

#endif /* BinarySearchTree_h */
