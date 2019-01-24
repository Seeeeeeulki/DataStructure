#include <stdio.h>
#include <stdlib.h>

#include "sort.h"

void selectionSort(Array* sort) {
	for (int i = 0; i < sort->size - 1; i++) {
		int min = i;
		for (int j = i + 1; j < sort->size; j++) {
			if (sort->arr[min] > sort->arr[j]) {
				min = j;
			}
		}
		if (min != i) {
			int temp = sort->arr[i];
			sort->arr[i] = sort->arr[min];
			sort->arr[min] = temp;
		}
	}
}

void bubbleSort(Array * sort) {
	for (int i = sort->size - 1; i != 0; i--) {
		for (int j = 0; j < i; j++) {
			if (sort->arr[j] > sort->arr[j + 1]) {
				int temp = sort->arr[j];
				sort->arr[j] = sort->arr[j + 1];
				sort->arr[j + 1] = temp;
			}
		}
	}

}

void print(Array * my) {
	for (int i = 0; i < my->size; i++) {
		printf("%d\t", my->arr[i]);
	}
}


Array * makeArray(int num)
{
	Array* arrr = (Array*)malloc(sizeof(Array));
	int* ar = (int*)malloc(sizeof(int)*num);
	for (int i = 0; i < num; i++) {
		ar[i] = rand() % num;
	}
	arrr->size = num;
	arrr->arr = ar;
	return arrr;
}


void mergeSort(Array * sort) {
	if (sort->size > 1) {
		int lsize = sort->size / 2;
		int rsize = (sort->size) - (sort->size / 2);
		int* left = (int*)malloc(sizeof(int)*lsize);
		int* right = (int*)malloc(sizeof(int)*rsize);
		Array* Left = (Array*)malloc(sizeof(Array));
		Array* Right = (Array*)malloc(sizeof(Array));
		for (int i = 0; i < lsize; i++) {
			left[i] = sort->arr[i];
		}
		for (int i = 0; i < rsize; i++) {
			right[i] = sort->arr[lsize + i];
		}
		Left->size = lsize;
		Left->arr = left;
		Right->size = rsize;
		Right->arr = right;

		mergeSort(Left);
		mergeSort(Right);

		Array* temp= merge(Left, Right);
		for (int i = 0; i < lsize + rsize; i++) {
			sort->arr[i] = temp->arr[i];
		}

		free(left);
		free(right);
		free(Left);
		free(Right);
		free(temp->arr);
		free(temp);
	}
}

Array* merge(Array* left, Array* right) {
	Array* rst = (Array*)malloc(sizeof(Array));
	rst->size = left->size + right->size;
	int* array = (int*)malloc(sizeof(int)*rst->size);
	int lidx = 0;
	int ridx = 0;
	int idx = 0;
	while (lidx < left->size && ridx < right->size) {
		if (left->arr[lidx] < right->arr[ridx]) {
			array[idx++] = left->arr[lidx++];
		}
		else {
			array[idx++] = right->arr[ridx++];
		}
	}
	while (lidx < left->size) {
		array[idx++] = left->arr[lidx++];
	}
	while (ridx < right->size) {
		array[idx++] = right->arr[ridx++];
	}
	rst->arr = array;
	return rst;
}



