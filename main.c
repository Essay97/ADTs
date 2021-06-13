#include <stdio.h>

#include "BST/BST.h"

int main(void) {
	BST t = BSTnew();
	int item;

	printf("TEST THIS\n");

	BSTprintInorder(t);

	BSTinsert(t, 100);
	BSTinsert(t, 20);	
	BSTinsert(t, 10);
	BSTinsert(t, 30);
	BSTinsert(t, 200);
	BSTinsert(t, 150);
	BSTinsert(t, 300);

	BSTprintInorder(t);

	printf("end\n");
	
	//LET THE PROGRAM OPEN
	printf("Press a key to close.\n");
	getchar();

  return 0;
}