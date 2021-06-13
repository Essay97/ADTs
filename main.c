#include <stdio.h>

#include "item.h"
#include "stack/stack.h"

int main(void) {
	Stack s = STACKnew(&ITEMdelete, ITEMsize());
	int i;
	Item item;

	STACKpush(s, ITEMnew(17));
	STACKpush(s, ITEMnew(88));

	while (!STACKisEmpty(s))
	{
		item = (Item)STACKpop(&ITEMcopy, s);
		printf("POPPED %d\n", ITEMget(item));
	}

  return 0;
}