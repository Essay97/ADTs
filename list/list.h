#ifndef LIST_H
#define LIST_H

typedef struct List_T *List;

List LISTnew(void);

void LISTdelete(List l);

void LISTinsertTail(List l, int x);

void LISTinsertHead(List l, int x);

void LISTinsertPos(List l, int pos, int x);

//TODO implement
void LISTdeleteTail(List l);

void LISTdeleteHead(List l);

void LISTdeletePos(List l, int pos);
//end TODO

void LISTprint(List l);

//GETTERS AND SETTERS

int LISTgetCount(List l);

int LISTgetItem(List l, int pos);

#endif