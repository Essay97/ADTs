#include <stdlib.h>
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

void ITEMdelete(Item i) {
	free(i);
}

int ITEMcompare(Item a, Item b) {
	return a->x - b->x;
}

//GETTERS AND SETTERS

int ITEMget(Item i) {
	return i->x;
}
