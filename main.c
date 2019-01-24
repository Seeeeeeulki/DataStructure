#include <stdio.h>
#include <stdlib.h>

#include "sort.h"


int main() {
	
	printf("\n/////////////selection////////////////////\n");
	Array* my = makeArray(50);
	print(my);
	printf("\n------------------------\n");
	selectionSort(my);
	print(my);
	printf("\n//////////////bubble///////////////////\n");
	Array* my2 = makeArray(50);
	print(my2);
	printf("\n------------------------\n");
	bubbleSort(my2);
	print(my2);
	printf("\n///////////////merge//////////////////\n");
	Array* my3 = makeArray(50);
	print(my3);
	printf("\n-----------------------\n");
	mergeSort(my3);
	print(my3);
	free(my);
	free(my2);
	free(my3);
}

