#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include "../list/list.h"
#include "../item.h"

typedef List Queue;

Queue QUEUEnew(void);

void QUEUEdelete(void (*destroy)(void *), Queue q);

void QUEUEenqueue(Queue q, Item x, size_t size);

void * QUEUEdequeue(void (*destroy)(void *), Queue q);

bool QUEUEisEmpty(Queue q);


#endif