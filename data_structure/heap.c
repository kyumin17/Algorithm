#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct {
	int last;
	int* arr;
} Heap;

Heap* create() {
	Heap* heap = (Heap *)malloc(sizeof(Heap));
	heap -> last = 0;
	heap -> arr = (int *)malloc(MAX_SIZE * sizeof(int));
	return heap;
}

int empty(Heap* heap) {
	if (heap -> last == 0)
		return 1;
	else
		return 0;
}

void swap(Heap* heap, int x, int y) {
	int temp = heap -> arr[x];
	heap -> arr[x] = heap -> arr[y];
	heap -> arr[y] = temp;
}

void push(Heap* heap, int data) {
	heap -> arr[++(heap -> last)] = data;
		
	int child = heap -> last;
	int parent = child/2;
	
	while (parent) {
		if (heap -> arr[parent] > heap -> arr[child]) {
			swap(heap, child, parent);
			child = parent;
			parent = parent/2;
		} else {
			break;
		}
	}
}

int pop(Heap* heap) {
	if (empty(heap))
		return -1;
	
	int top = heap -> arr[1];
	heap -> arr[1] = heap -> arr[(heap -> last)--];
	int parent = 1;
	int child = 2;
	
	while (child <= heap -> last) {
		if (heap -> arr[parent] < heap -> arr[child] && heap -> arr[parent] < heap -> arr[child+1]) {
			break;
		} else if (heap -> arr[parent] > heap -> arr[child] && heap -> arr[child] < heap -> arr[child+1]) {
			swap(heap, parent, child);
		} else {
			swap(heap, parent, ++child);
		}
		parent = child;
		child = parent * 2;
	}
	
	return top;
}

void print(Heap* heap) {
	int i;
	for (i = 1; i <= heap -> last; i++)
		printf("%d ", heap -> arr[i]);
	printf("\n");
}

void del(Heap* heap) {
	free(heap -> arr);
	free(heap);
}
