#ifndef ITEM_H
#define ITEM_H

typedef struct Item_T *Item;

Item ITEMnew(int n);

void ITEMdelete(Item c);

int ITEMcompare(Item a, Item b);

//GETTERS AND SETTERS

int ITEMget(Item c);

#endif