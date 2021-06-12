#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include "../list/list.h"

typedef List Queue;

Queue QUEUEnew(void);

void QUEUEdelete(Queue q);

void QUEUEenqueue(Queue q, int x);

int QUEUEdequeue(Queue q);

bool QUEUEisEmpty(Queue q);


#endif