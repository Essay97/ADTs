#include <stdlib.h>
#include <stdio.h>

#include "item.h"

struct Item_T {
    int x;
};

Item ITEMnew(int n) {
	Item i;

	i = (Item)malloc(sizeof(struct Item_T));
	i->x = n;

	return i;
}

void ITEMdelete(void *i) {
	free(i);
}

int ITEMcompare(void *a, void *b) {
	return ((Item)a)->x - ((Item)b)->x;
}

size_t ITEMsize(void) {
	return sizeof(struct Item_T);
}

void * ITEMcopy(void *i) {
	return ITEMnew(ITEMget(i));
}

char * ITEMstring(void *i) {
	char *str;
	sprintf(str, "%d", ((Item)i)->x);
	return str;
}

//GETTERS AND SETTERS

int ITEMget(Item i) {
	return i->x;
}

void ITEMset(Item i, int newVal) {
	i->x = newVal;
}
