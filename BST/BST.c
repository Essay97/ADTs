#include <stdlib.h>
#include <stdio.h>
#include "btnode.h"
#include "BST.h"

struct BST_T {
	BTNode head;
	void (*destructor)(void *);
	int (*compare)(void *, void *);
	size_t size;
};

//PRIVATE FUNCTIONS
static void deleteTree(void (*destructor)(void *), BTNode n) {
	if(BTNODEisLeaf(n)) {
		BTNODEdelete(destructor, n);
		return;
	}

	deleteTree(destructor, BTNODEgetLeft(n));
	deleteTree(destructor, BTNODEgetRight(n));

	BTNODEdelete(destructor, n);
}

static void insertNode(int (*compare)(void *, void *), BTNode n, BTNode newNode) {
	BTNode tmp;

	if(BTNODEisLeaf(n)) {
		if(BTNODEcompare(compare, newNode, n) <= 0) {
			BTNODEsetLeft(n, newNode);
		} else {
			BTNODEsetRight(n, newNode);
		}
		return; 
	}

	if(BTNODEcompare(compare, newNode, n) <= 0) {
		tmp = BTNODEgetLeft(n);
		if(tmp != NULL) {
			insertNode(compare, tmp, newNode);
		} else {
			BTNODEsetLeft(n, newNode);
			return;
		}
	} else {
		tmp = BTNODEgetRight(n);
		if(tmp != NULL) {
			insertNode(compare, tmp, newNode);
		} else {
			BTNODEsetRight(n, newNode);
			return;
		}
	}
}

static void inorder(char * (*toString)(void *), BTNode n) {
	if(BTNODEisLeaf(n)) {
		printf("%s\n", toString(BTNODEgetData(n)));
		return;
	}

	inorder(toString, BTNODEgetLeft(n));
	printf("test inorder\n");
	printf("%s\n", toString(BTNODEgetData(n)));
	inorder(toString, BTNODEgetRight(n));
}

static void preorder(char * (*toString)(void *), BTNode n) {
	if(BTNODEisLeaf(n)) {
		printf("%s\n", toString(BTNODEgetData(n)));
		return;
	}

	printf("%s\n", BTNODEgetData(n));
	preorder(toString, BTNODEgetLeft(n));
	preorder(toString, BTNODEgetRight(n));
}

static void postorder(char * (*toString)(void *), BTNode n) {
	if(BTNODEisLeaf(n)) {
		printf("%s\n", BTNODEgetData(n));
		return;
	}

	postorder(toString, BTNODEgetLeft(n));
	postorder(toString, BTNODEgetRight(n));
	printf("%s\n", BTNODEgetData(n));
}


//PUBLIC FUNCTIONS

BST BSTnew(void (*destroy)(void *), int (*cmp)(void *, void *)) {
	BST t;

	t = (BST)malloc(sizeof(struct BST_T));
	t->head = NULL;
	t->destructor = destroy;
	t->compare = cmp;

	return t;
}

void BSTdelete(BST t) {
	deleteTree(t->destructor, t->head);
	free(t);
}

void BSTinsert(BST t, void *data) {
	BTNode newNode = BTNODEnew(data, t->size);
	
	if(t->head == NULL) {
		t->head = newNode;
	} else {
		insertNode(t->compare, t->head, newNode);
	}
	
}

//TODO add function that returns string from data as a parameter for the print methods

void BSTprintInorder(char * (*toString)(void *), BST t) {
	if(t->head == NULL) {
		printf("Empty tree\n");
	} else {
		inorder(toString, t->head);
	}
}

void BSTprintPreorder(char * (*toString)(void *), BST t) {
	if(t->head == NULL) {
		printf("Empty tree\n");
	} else {
		preorder(toString, t->head);
	}
}

void BSTprintPostorder(char * (*toString)(void *), BST t) {
	if(t->head == NULL) {
		printf("Empty tree\n");
	} else {
		postorder(toString, t->head);
	}
}

//GETTERS AND SETTERS

//Debug
BTNode getHead(BST t) {
	return t->head;
}