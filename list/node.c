#include <stdlib.h>
#include "../item.h"
#include "node.h"

struct Node_T {
	void *x;
	Node next;
};

Node NODEnew(void *data, size_t size) {
	Node n;
	n = (Node)malloc(sizeof(struct Node_T));
	n->x = malloc(size);
	n->x = data;
	n->next = NULL;
	return n;
}

void NODEdelete(void (*destroy)(void *), Node n) {
	(*destroy)(n->x); 
	n->next = NULL;
	free(n);
}

//GETTERS AND SETTERS

void NODEsetNext(Node n, Node next) {
	n->next = next;
}

Node NODEgetNext(Node n) {
	return n->next;
}

void * NODEgetData(Node n) {
	return n->x;
}