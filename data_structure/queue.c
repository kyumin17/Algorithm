#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct {
	int front;
	int rear;
	int* arr;
} Queue;

Queue* create() {
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	queue -> front = 0;
	queue -> rear = -1;
	queue -> arr = (int *)malloc(MAX_SIZE * sizeof(int));
	return queue;
}

int empty(Queue* queue) {
	if (queue -> front > queue -> rear)
		return 1;
	else
		return 0;
}

void push(Queue* queue, int data) {
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
	for (i = queue -> front; i <= queue -> rear; i++)
		printf("%d ", queue -> arr[i]);
	printf("\n");
}

void del(Queue* queue) {
	free(queue -> arr);
	free(queue);
}
