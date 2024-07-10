#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int front;
	int rear;
	int size;
	int* arr;
} Queue;

Queue* create(int size) {
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	queue -> front = 0;
	queue -> rear = -1;
	queue -> size = size;
	queue -> arr = (int *)malloc(size * sizeof(int));
	return queue;
}

int empty(Queue* queue) {
	if (queue -> front > queue -> rear)
		return 1;
	else
		return 0;
}

int full(Queue* queue) {
	if (queue -> rear == (queue -> size) - 1)
		return 1;
	else
		return 0;
}

void push(Queue* queue, int data) {
	if (full(queue)) {
		queue -> size *= 2;
		queue -> arr = (int *)realloc(queue -> arr, (queue -> size) * 2 * sizeof(int));
	}
	queue -> arr[++(queue -> rear)] = data;
}

int pop(Queue* queue) {
	if (empty(queue))
		return -1;
	else
		queue -> arr[(queue -> front)++];
}

void print(Queue* queue) {
	int i;
	for (i = queue -> front; i <= queue -> rear; i++) {
		printf("%d ", queue -> arr[i]);
	}
}

void clear(Queue* queue) {
	queue -> front = 0;
	queue -> rear = -1;
}
