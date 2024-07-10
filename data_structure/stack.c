#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int top;
	int size;
	int* arr;
} Stack;

Stack* create(int size) {
	Stack* stack = (Stack *)malloc(sizeof(Stack));
	stack -> top = -1;
	stack -> size = size;
	stack -> arr = (int *)malloc(size * sizeof(int));
	return stack;
}

int empty(Stack* stack) {
	if (stack -> top == -1)
		return 1;
	else
		return 0;
}

int full(Stack* stack) {
	if (stack -> top == (stack -> size) - 1)
		return 1;
	else
		return 0;
}

void push(Stack* stack, int data) {
	if (full(stack)) {
		stack -> size *= 2;
		stack -> arr = (int *)realloc(stack -> arr, (stack -> size) * 2 * sizeof(int));
	}
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
}

void clear(Stack* stack) {
	stack -> top = -1;
}
