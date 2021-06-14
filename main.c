#include <stdio.h>

#include "item.h"
#include "BST/BST.h"

int main(void) {
	BST t;
	
	t = BSTnew(&ITEMdelete, &ITEMcompare);
	BSTinsert(t, ITEMnew(5));
	BSTinsert(t, ITEMnew(44));
	BSTinsert(t, ITEMnew(89));
	BSTinsert(t, ITEMnew(66));

	BSTprintInorder(&ITEMstring, t);
	printf("end\n");

	printf("L M A O\n");

	printf("HEEEEEEEEY");
  return 0;
}