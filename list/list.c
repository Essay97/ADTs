#include <stdlib.h>
#include <stdio.h>
#include "node.h"
#include "list.h"

struct List_T {
	Node head;
	int count;
};

List LISTnew(void) {
	List l;
	l = (List)malloc(sizeof(struct List_T));
	l->head = NULL;
	l->count = 0;
	return l;
}

void LISTdelete(void (*destroy)(void *), List l) {
	Node tmp;
	while(l->head != NULL) {
		tmp = l->head;
		l->head = NODEgetNext(l->head);
		NODEdelete(destroy, tmp);
	}
	free(l);
}

void LISTinsertTail(List l, void *data, size_t size) {
	Node curr = l->head;
	Node prev = NULL;
	Node newNode = NODEnew(data, size);

	//navigate to the end of the list
	while(curr != NULL) {
		prev = curr;
		curr = NODEgetNext(curr);
	}

	if(prev == NULL) {
		l->head = newNode;
	} else {
		NODEsetNext(prev, newNode);
	}
	(l->count)++;
}

void LISTinsertHead(List l, void *data, size_t size) {
	Node tmp = l->head;
	l->head = NODEnew(data, size);
	NODEsetNext(l->head, tmp);
	(l->count)++;
}

void LISTinsertPos(List l, int pos, void *data, size_t size) {
	Node curr = l->head;
	Node prev = NULL;
	Node newNode = NODEnew(data, size);

	if(pos < 0 || pos >= l->count) {
		fprintf(stderr, "Position is not valid!\n");
		exit(-1);
	}

	while(pos > 0) {
		prev = curr;
		curr = NODEgetNext(curr);
		pos--;
	}

	if(prev == NULL) {
		LISTinsertHead(l, data, size);
	} else {
		NODEsetNext(prev, newNode);
		NODEsetNext(newNode, curr);
	}
	
	(l->count)++;
}

void LISTdeleteTail(void (*destroy)(void *), List l) {
	Node curr = l->head;
	Node prev = NULL, sec_prev = NULL;

	if(l->head == NULL) {
		fprintf(stderr, "List is empty!");
		exit(-1);
	}

	while(curr != NULL) {
		sec_prev = prev;
		prev = curr;
		curr = NODEgetNext(curr);
	}

	if(sec_prev != NULL) {
		NODEdelete(destroy, prev);
		NODEsetNext(sec_prev, NULL);
		(l->count)--;
	} else if(prev != NULL) {
		NODEdelete(destroy, prev);
		l->head = NULL;
		(l->count)--;
	}
}

void LISTdeleteHead(void (*destroy)(void *), List l) {
	Node tmp;
	
	if(l->head == NULL) {
		fprintf(stderr, "List is empty!");
		exit(-1);
	}
	
	if(l->head != NULL) {
		tmp = NODEgetNext(l->head);
		NODEdelete(destroy, l->head);
		l->head = tmp;
		(l->count)--;
	}
}

void LISTdeletePos(void (*destroy)(void *), List l, int pos) {
	Node curr = l->head;
	Node prev = NULL;
	Node tmp;

	if(pos < 0 || pos >= l->count) {
		fprintf(stderr, "Position is not valid!\n");
		exit(-1);
	}
	
	while(pos > 0) {
		prev = curr;
		curr = NODEgetNext(curr);
		pos--;
	}

	tmp = NODEgetNext(curr);
	NODEsetNext(prev, tmp);
	NODEdelete(destroy, curr);

	(l->count)--;
}

/* void LISTprint(List l) {
	Node n = l->head;

	if(l->head == NULL) {
		printf("Empty list \n");
	} else {
		while(n != NULL) {
		printf("%d\n", NODEgetItem(n));
		n = NODEgetNext(n);
	}
	}
} */

//GETTERS AND SETTERS

int LISTgetCount(List l) {
	return l->count;
}

void * LISTgetItem(List l, int pos) {
	Node curr = l->head;

	while(pos > 0) {
		curr = NODEgetNext(curr);
		pos--;
	}
	return NODEgetData(curr);
}