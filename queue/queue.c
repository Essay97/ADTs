#include <stdlib.h>
#include <stdio.h>
#include "../list/list.h"
#include "queue.h"

Queue QUEUEnew(void (*destroy)(void *), size_t size) {
	Queue q;
	q = LISTnew(destroy, size);
	return q;
}

void QUEUEdelete(Queue q) {
	LISTdelete(q);
}

void QUEUEenqueue(Queue q, void *x) {
	LISTinsertTail(q, x);
}

void * QUEUEdequeue(void * (*copy)(void *), Queue q) {
	if(LISTgetCount(q) == 0) {
		fprintf(stderr, "Queue is empty!");
		exit(-1);
	}

	void *x = LISTcopyItem(copy, q, 0);
	LISTdeleteHead(q);
	return x;
}

bool QUEUEisEmpty(Queue q) {
	return LISTgetCount(q) == 0;
}


