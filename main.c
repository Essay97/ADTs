#include <stdio.h>

#include "BST/BST.h"

int main(void) {
	BST t = BSTnew();

	BSTinsert(t, 100);
	BSTinsert(t, 20);
	BSTinsert(t, 10);
	/* BSTinsert(t, 30);
	BSTinsert(t, 200);
	BSTinsert(t, 150);
	BSTinsert(t, 300); */

	/* BSTprintInorder(t); */

	printf("end\n");
	
  return 0;
}