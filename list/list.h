#ifndef LIST_H
#define LIST_H

typedef struct List_T *List;

/* Returns a new empty list */
List LISTnew(void (*destroy)(void *), size_t size);

/* Deallocates the list and all the nodes that compose it
      params:
        destroy: a function that destroys the data in the nodes
        l: the list you want to destroy */
void LISTdelete(List l);

void LISTinsertTail(List l, void *data);

void LISTinsertHead(List l, void *data);

void LISTinsertPos(List l, int pos, void *data);

void LISTdeleteTail(List l);

void LISTdeleteHead(List l);

void LISTdeletePos(List l, int pos);

void * LISTcopyItem(void * (*copy)(void *), List l, int pos);

//GETTERS AND SETTERS

int LISTgetCount(List l);

void * LISTgetItem(List l, int pos);

#endif