#include <stdlib.h>
#include <stdio.h>
#include "../list/list.h"
#include "queue.h"

Queue QUEUEnew(void) {
	Queue q;
	q = LISTnew();
	return q;
}

void QUEUEdelete(Queue q) {
	LISTdelete(q);
}

void QUEUEenqueue(Queue q, int x) {
	LISTinsertTail(q, x);
}

int QUEUEdequeue(Queue q) {
	if(LISTgetCount(q) == 0) {
		fprintf(stderr, "Stack is empty!");
		exit(-1);
	}

	int x = LISTgetItem(q, 0);
	LISTdeleteHead(q);
	return x;
}

bool QUEUEisEmpty(Queue q) {
	return LISTgetCount(q) == 0;
}


