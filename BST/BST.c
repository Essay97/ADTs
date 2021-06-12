#include <stdlib.h>
#include <stdio.h>
#include "btnode.h"
#include "BST.h"

struct BST_T {
	BTNode head;
};

//PRIVATE FUNCTIONS
static void deleteTree(BTNode n) {
	if(BTNODEisLeaf(n)) {
		BTNODEdelete(n);
		return;
	}

	deleteTree(BTNODEgetLeft(n));
	deleteTree(BTNODEgetRight(n));

	BTNODEdelete(n);
}

static void insertNode(BTNode n, BTNode newNode) {
	if(BTNODEisLeaf(n)) {
		BTNODEcompare(n, newNode) <= 0 ? BTNODEsetLeft(n, newNode) : BTNODEsetRight(n, newNode);
		return; 
	}

	BTNODEcompare(n, newNode) <= 0 ? insertNode(BTNODEgetLeft(n), newNode) : insertNode(BTNODEgetLeft(n), newNode); 
}

static void inorder(BTNode n) {
	if(BTNODEisLeaf(n)) {
		printf("%d\n", BTNODEgetItem(n));
		return;
	}

	inorder(BTNODEgetLeft(n));
	printf("%d\n", BTNODEgetItem(n));
	inorder(BTNODEgetRight(n));
}

static void preorder(BTNode n) {
	if(BTNODEisLeaf(n)) {
		printf("%d\n", BTNODEgetItem(n));
		return;
	}

	printf("%d\n", BTNODEgetItem(n));
	preorder(BTNODEgetLeft(n));
	preorder(BTNODEgetRight(n));
}

static void postorder(BTNode n) {
	if(BTNODEisLeaf(n)) {
		printf("%d\n", BTNODEgetItem(n));
		return;
	}

	postorder(BTNODEgetLeft(n));
	postorder(BTNODEgetRight(n));
	printf("%d\n", BTNODEgetItem(n));
}


//PUBLIC FUNCTIONS

BST BSTnew(void) {
	BST t;

	t = (BST)malloc(sizeof(struct BST_T));
	t->head = NULL;

	return t;
}

void BSTdelete(BST t) {
	deleteTree(t->head);
	free(t);
}

void BSTinsert(BST t, int x) {
	BTNode newNode = BTNODEnew(x);
	
	if(t->head == NULL) {
		t->head = newNode;
	} else {
		insertNode(t->head, newNode);
	}
	
}

void BSTprintInorder(BST t) {
	inorder(t->head);
}

void BSTprintPreorder(BST t) {
	preorder(t->head);
}

void BSTprintPostorder(BST t) {
	postorder(t->head);
}

