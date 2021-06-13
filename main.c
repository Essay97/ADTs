#include <stdio.h>

#include "BST/BST.h"
#include "item.h"
#include "list/list.h"

int main(void) {
	List l = LISTnew();
	size_t itemSize = ITEMsize();
	int i, listCount;
	Item item;

	LISTinsertHead(l, ITEMnew(5), itemSize);
	LISTinsertHead(l, ITEMnew(48), itemSize);

	listCount = LISTgetCount(l);

	for(i = 0; i < listCount; i++) {
		item = LISTgetItem(l, i);
		printf("ELEMENT: %d\n", ITEMget(item));
	}

	LISTdeleteHead(&ITEMdelete, l);
	for(i = 0; i < listCount; i++) {
		item = LISTgetItem(l, i);
		printf("ELEMENT: %d\n", ITEMget(item));
	}




  return 0;
}