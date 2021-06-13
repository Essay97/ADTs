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

void ITEMdelete(void *i) {
	free(i);
}

int ITEMcompare(Item a, Item b) {
	return a->x - b->x;
}

size_t ITEMsize(void) {
	return sizeof(struct Item_T);
}

//GETTERS AND SETTERS

int ITEMget(Item i) {
	return i->x;
}
