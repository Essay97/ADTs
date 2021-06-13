#ifndef LIST_H
#define LIST_H

typedef struct List_T *List;

/* Returns a new empty list */
List LISTnew(void);

/* Deallocates the list and all the nodes that compose it
      params:
        destroy: a function that destroys the data in the nodes
        l: the list you want to destroy */
void LISTdelete(void (*destroy)(void *), List l);

void LISTinsertTail(List l, void *data, size_t size);

void LISTinsertHead(List l, void *data, size_t size);

void LISTinsertPos(List l, int pos, void *data, size_t size);

void LISTdeleteTail(void (*destroy)(void *), List l);

void LISTdeleteHead(void (*destroy)(void *), List l);

void LISTdeletePos(void (*destroy)(void *), List l, int pos);

//void LISTprint(List l);

//GETTERS AND SETTERS

int LISTgetCount(List l);

void * LISTgetItem(List l, int pos);

#endif