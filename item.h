#ifndef ITEM_H
#define ITEM_H

typedef struct Item_T *Item;

Item ITEMnew(int n);

void ITEMdelete(void * c);

int ITEMcompare(Item a, Item b);

size_t ITEMsize(void);

void * ITEMcopy(void *i);

//GETTERS AND SETTERS

int ITEMget(Item i);

void ITEMset(Item i, int newVal);

#endif