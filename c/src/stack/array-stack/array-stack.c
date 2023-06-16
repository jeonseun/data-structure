#include "array-stack.h"

void initStack(Stack *stack) {
    stack->top = -1;
    stack->size = 0;
}

int isFull(Stack *stack) {
    return stack->size == STACK_SIZE;
}

int push(Stack *stack, int data) {
    if (isFull(stack)) {
        return -1;
    }

    stack->data[++stack->top] = data;
    return ++stack->size;
}

int isEmpty(Stack *stack) {
    return stack->size == 0;
}

int pop(Stack *stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    stack->size--;
    return stack->data[stack->top--];
}

int peek(Stack *stack) {
    if (isEmpty(stack)) {
        return -1;
    }

    return stack->data[stack->top];
}

int search(Stack *stack, int data) {
    if (isEmpty(stack)) {
        return -1;
    }
    int popCount = 1;
    for (int i = stack->top; i >= 0; i--) {
        if (stack->data[i] == data) {
            return popCount;
        }
        popCount++;
    }
    return -1;
}

void printAll(Stack *stack) {
    printf("=> stack size: %d\n", stack->size);
    int size = stack->size - 1;
    printf("   │ %2d │ <-- top\n", peek(stack));

    while (size--) {
        printf("   │ %2d │\n", stack->data[size]);
    }
    printf("   └────┘\n");
}