#include <stdio.h>

#include "item.h"
#include "queue/queue.h"

/* TODO It should be possible to pass the destructor and the size only once, when the data structure is instantiated, 
store them inside the data structure and then always take it from there */

int main(void) {
	Queue q = QUEUEnew();
	size_t itemSize = ITEMsize();
	int i;
	Item item;

	QUEUEenqueue(q, ITEMnew(4), itemSize);
	QUEUEenqueue(q, ITEMnew(8), itemSize);

	while (!QUEUEisEmpty(q))
	{
		item = (Item)QUEUEdequeue(&ITEMdelete, q);
		printf("DEQUEUED %d\n", ITEMget(item));
	}
	





  return 0;
}