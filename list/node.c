#include <stdlib.h>
#include "../item.h"
#include "node.h"

struct Node_T {
	Item c;
	Node next;
};

Node NODEnew(int x) {
	Node n;
	n = (Node)malloc(sizeof(struct Node_T));
	n->c = ITEMnew(x);
	n->next = NULL;
	return n;
}

void NODEdelete(Node n) {
	ITEMdelete(n->c);
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

int NODEgetItem(Node n) {
	return ITEMget(n->c);
}