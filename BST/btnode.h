#ifndef BTNODE_H
#define BTNODE_H

#include <stdbool.h>

typedef struct BTNode_T *BTNode;

BTNode BTNODEnew(int x);

void BTNODEdelete(BTNode n);

bool BTNODEisLeaf(BTNode n);

int BTNODEcompare(BTNode a, BTNode b);

// GETTERS AND SETTERS

BTNode BTNODEgetLeft(BTNode n);

BTNode BTNODEgetRight(BTNode n);

void BTNODEsetLeft(BTNode n, BTNode newNode);

void BTNODEsetRight(BTNode n, BTNode newNode);

int BTNODEgetItem(BTNode n);

#endif 