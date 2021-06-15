#include <stdio.h>

#include "item.h"
#include "BST/BST.h"

int main(void) {
	BST t;
	
	t = BSTnew(&ITEMdelete, &ITEMcompare);
	BSTinsert(t, ITEMnew(50));
	BSTinsert(t, ITEMnew(44));
	BSTinsert(t, ITEMnew(89));
	BSTinsert(t, ITEMnew(11));	

	BSTprintPreorder(&ITEMstring, t);
	
	BSTdelete(t);
	t = BSTnew(&ITEMdelete, &ITEMcompare);
	BSTprintPreorder(&ITEMstring, t);
  return 0;
}