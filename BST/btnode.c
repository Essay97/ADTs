#include <stdlib.h>
#include <stdio.h>
#include "btnode.h"
#include "../item.h"

struct BTNode_T {
	void *x;
	BTNode left;
	BTNode right;
};

BTNode BTNODEnew(void *x, size_t size) {
	BTNode n;
	n = (BTNode)malloc(sizeof(struct BTNode_T));

	n->x = malloc(size);
	n->x = x;
	n->right = NULL;
	n->left = NULL;

	return n;
}

void BTNODEdelete(void (*destroy)(void *), BTNode n) {
	(*destroy)(n->x);
	n->right = NULL;
	n->left = NULL;

	free(n);
}

bool BTNODEisLeaf(BTNode n) {
	return (n->left == NULL && n->right == NULL);
}

int BTNODEcompare(int (*cmp)(void *, void *), BTNode a, BTNode b) {
	return (*cmp)(a->x, b->x);
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

void * BTNODEgetData(BTNode n) {
	return n->x;
}