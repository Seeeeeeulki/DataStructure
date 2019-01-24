#ifndef __SORT_H__
#define __SORT_H__

typedef struct Array {
	int size;
	int*arr;
}Array;

Array* makeArray(int num);
void selectionSort(Array* sort);
void bubbleSort(Array*sort);
void print(Array* arr);

void mergeSort(Array* sort);
Array* merge(Array* left, Array* right);


#endif

