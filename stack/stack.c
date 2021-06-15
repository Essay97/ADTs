#include <stdlib.h>
#include <stdio.h>
#include "../list/list.h"
#include "stack.h"

Stack STACKnew(void (*destroy)(void *), size_t size) {
	Stack s = LISTnew(destroy, size);

	return s;
}

void STACKdelete(Stack s) {
	LISTdelete(s);
} 

void STACKpush(Stack s, void *x) {
	LISTinsertTail(s, x);
}

void * STACKpop(void * (*copy)(void *), Stack s) {
	if(LISTgetCount(s) == 0) {
		fprintf(stderr, "Stack is empty!");
		exit(-1);
	} 

	void *x = LISTcopyItem(copy, s, LISTgetCount(s) - 1);
	LISTdeleteTail(s);

	return x;
}

bool STACKisEmpty(Stack s) {
	return LISTgetCount(s) == 0;
}

