#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include "../list/list.h"


typedef List Stack;

Stack STACKnew(void (*destroy)(void *), size_t size);

void STACKdelete(Stack s);

void STACKpush(Stack s, void *x);

void * STACKpop(void * (*copy)(void *), Stack s);

bool STACKisEmpty(Stack s);

#endif