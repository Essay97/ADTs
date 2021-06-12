#include <stdlib.h>
#include <stdio.h>
#include "../list/list.h"
#include "stack.h"

Stack STACKnew(void) {
	Stack s = LISTnew();

	return s;
}

void STACKdelete(Stack s) {
	LISTdelete(s);
} 

void STACKpush(Stack s, int x) {
	LISTinsertTail(s, x);
}

int STACKpop(Stack s) {
	if(LISTgetCount(s) == 0) {
		fprintf(stderr, "Stack is empty!");
		exit(-1);
	} 

	int x = LISTgetItem(s, LISTgetCount(s) - 1);
	LISTdeleteTail(s);

	return x;
}

bool STACKisEmpty(Stack s) {
	return LISTgetCount(s) == 0;
}

