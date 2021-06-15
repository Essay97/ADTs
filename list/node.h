#ifndef NODE_H
#define NODE_H

typedef struct Node_T *Node;

Node NODEnew(void *data, size_t size);

void NODEdelete(void (*destroy)(void *), Node n);

//GETTERS AND SETTERS

void NODEsetNext(Node n, Node next);

Node NODEgetNext(Node n);

void * NODEgetData(Node n);

#endif