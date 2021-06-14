#ifndef BTNODE_H
#define BTNODE_H

#include <stdbool.h>

typedef struct BTNode_T *BTNode;

BTNode BTNODEnew(void *data, size_t size);

void BTNODEdelete(void (*destroy)(void *), BTNode n);

bool BTNODEisLeaf(BTNode n);

int BTNODEcompare(int (*cmp)(void *, void *), BTNode a, BTNode b);

// GETTERS AND SETTERS

BTNode BTNODEgetLeft(BTNode n);

BTNode BTNODEgetRight(BTNode n);

void BTNODEsetLeft(BTNode n, BTNode newNode);

void BTNODEsetRight(BTNode n, BTNode newNode);

void * BTNODEgetData(BTNode n);

#endif 