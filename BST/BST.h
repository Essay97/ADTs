#ifndef BST_H
#define BST_H

#include "btnode.h"

typedef struct BST_T *BST;

BST BSTnew(void (*destroy)(void *), int (*cmp)(void *, void *));

void BSTdelete(BST t);

void BSTinsert(BST t, void *data);

void BSTprintInorder(char * (*toString)(void *), BST t);

void BSTprintPreorder(char * (*toString)(void *), BST t);

void BSTprintPostorder(char * (*toString)(void *), BST t);

//GETTERS AND SETTERS 

//TODO remove this section
//Debug
BTNode getHead(BST t);

#endif