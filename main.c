#include <stdio.h>

#include "item.h"
#include "queue/queue.h"

int main(void) {
	Queue q = QUEUEnew(&ITEMdelete, ITEMsize());
	int i;
	Item item;

	QUEUEenqueue(q, ITEMnew(4));
	QUEUEenqueue(q, ITEMnew(8));

	while (!QUEUEisEmpty(q))
	{
		item = (Item)QUEUEdequeue(&ITEMcopy, q);
		printf("DEQUEUED %d\n", ITEMget(item));
	}

  return 0;
}