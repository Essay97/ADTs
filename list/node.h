#ifndef NODE_H
#define NODE_H

typedef struct Node_T *Node;

Node NODEnew(int x);

void NODEdelete(Node n);

//GETTERS AND SETTERS

void NODEsetNext(Node n, Node next);

Node NODEgetNext(Node n);

int NODEgetItem(Node n);

#endif