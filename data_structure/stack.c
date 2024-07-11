#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct {
	int top;
	int* arr;
} Stack;

Stack* create() {
	Stack* stack = (Stack *)malloc(sizeof(Stack));
	stack -> top = -1;
	stack -> arr = (int *)malloc(MAX_SIZE * sizeof(int));
	return stack;
}

int empty(Stack* stack) {
	if (stack -> top == -1)
		return 1;
	else
		return 0;
}

void push(Stack* stack, int data) {
	stack -> arr[++(stack -> top)] = data;
}

int pop(Stack* stack) {
	if (empty(stack))
		return -1;
	else
		return stack -> arr[(stack -> top)--];
}

void print(Stack* stack) {
	int i;
	for (i = 0; i <= stack -> top; i++)
		printf("%d ", stack -> arr[i]);
	printf("\n");
}

void del(Stack* stack) {
	free(stack -> arr);
	free(stack);
}
