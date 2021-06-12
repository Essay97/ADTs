#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include "../list/list.h"


typedef List Stack;

Stack STACKnew(void);

void STACKdelete(Stack s);

void STACKpush(Stack s, int x);

int STACKpop(Stack s);

bool STACKisEmpty(Stack s);

#endif