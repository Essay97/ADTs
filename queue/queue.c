#include <stdlib.h>
#include <stdio.h>
#include "../list/list.h"
#include "queue.h"

Queue QUEUEnew(void) {
	Queue q;
	q = LISTnew();
	return q;
}

void QUEUEdelete(void (*destroy)(void *), Queue q) {
	LISTdelete(destroy, q);
}

void QUEUEenqueue(Queue q, Item x, size_t size) {
	LISTinsertTail(q, x, size);
}

void * QUEUEdequeue(void (*destroy)(void *), Queue q) {
	if(LISTgetCount(q) == 0) {
		fprintf(stderr, "Queue is empty!");
		exit(-1);
	}

	void *x = LISTgetItem(q, 0);
	printf("TESTING VALUE: %d\n", ITEMget((Item)x));
	LISTdeleteHead(destroy, q);
	return x;
}

bool QUEUEisEmpty(Queue q) {
	return LISTgetCount(q) == 0;
}


