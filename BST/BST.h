#ifndef BST_H
#define BST_H

typedef struct BST_T *BST;

BST BSTnew(void);

void BSTdelete(BST t);

void BSTinsert(BST t, int x);

void BSTprintInorder(BST t);

void BSTprintPreorder(BST t);

void BSTprintPostorder(BST t);

#endif