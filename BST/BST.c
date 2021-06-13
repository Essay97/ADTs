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
	BTNode tmp;

	if(BTNODEisLeaf(n)) {
		if(BTNODEcompare(newNode, n) <= 0) {
			BTNODEsetLeft(n, newNode);
		} else {
			BTNODEsetRight(n, newNode);
		}
		return; 
	}

	if(BTNODEcompare(newNode, n) <= 0) {
		tmp = BTNODEgetLeft(n);
		if(tmp != NULL) {
			insertNode(tmp, newNode);
		} else {
			BTNODEsetLeft(n, newNode);
			return;
		}
	} else {
		tmp = BTNODEgetRight(n);
		if(tmp != NULL) {
			insertNode(tmp, newNode);
		} else {
			BTNODEsetRight(n, newNode);
			return;
		}
	}
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
	if(t->head == NULL) {
		printf("Empty tree\n");
	} else {
		inorder(t->head);
	}
}

void BSTprintPreorder(BST t) {
	if(t->head == NULL) {
		printf("Empty tree\n");
	} else {
		preorder(t->head);
	}
}

void BSTprintPostorder(BST t) {
	if(t->head == NULL) {
		printf("Empty tree\n");
	} else {
		postorder(t->head);
	}
}

//GETTERS AND SETTERS

//Debug
BTNode getHead(BST t) {
	return t->head;
}