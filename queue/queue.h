#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include "../list/list.h"
#include "../item.h"

typedef List Queue;

Queue QUEUEnew(void (*destroy)(void *), size_t size);
void QUEUEdelete( Queue q);

void QUEUEenqueue(Queue q, void *x);

void * QUEUEdequeue(void * (*copy)(void *), Queue q);

bool QUEUEisEmpty(Queue q);


#endif