#include <stdlib.h>
#include <stdio.h>
#include "btnode.h"
#include "../item.h"

struct BTNode_T {
	Item i;
	BTNode left;
	BTNode right;
};

BTNode BTNODEnew(int x) {
	BTNode n;
	n = (BTNode)malloc(sizeof(struct BTNode_T));

	n->i = ITEMnew(x);
	n->right = NULL;
	n->left = NULL;

	return n;
}

void BTNODEdelete(BTNode n) {
	ITEMdelete(n->i);
	n->right = NULL;
	n->left = NULL;

	free(n);
}

bool BTNODEisLeaf(BTNode n) {
	return (n->left == NULL && n->right == NULL);
}

int BTNODEcompare(BTNode a, BTNode b) {
	return ITEMcompare(a->i, b->i);
}

//GETTERS AND SETTERS 

BTNode BTNODEgetLeft(BTNode n) {
	return n->left;
}

BTNode BTNODEgetRight(BTNode n) {
	return n->right;
}

void BTNODEsetLeft(BTNode n, BTNode newNode) {
	n->left = newNode;
}

void BTNODEsetRight(BTNode n, BTNode newNode) {
	n->right = newNode;
}

int BTNODEgetItem(BTNode n) {
	return ITEMget(n->i);
}