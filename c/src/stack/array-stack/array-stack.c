#include "array-stack.h"

void initStack(Stack *stack) {
    stack->top = -1;
    stack->size = 0;
}

int isFull(Stack *stack) {
    return stack->size == STACK_SIZE;
}

int push(Stack *stack, char *data) {
    if (isFull(stack)) {
        return -1;
    }

    stack->top++;
    stack->data[stack->top] = (char *) malloc(sizeof(char) * strlen(data) + 1);
    strcpy(stack->data[stack->top], data);
    return ++stack->size;
}

int isEmpty(Stack *stack) {
    return stack->size == 0;
}

char *pop(Stack *stack) {
    if (isEmpty(stack)) {
        return NULL;
    }

    char *temp = (char *) malloc(sizeof(char) * strlen(stack->data[stack->top]));
    strcpy(temp, stack->data[stack->top]);
    free(stack->data[stack->top]);
    stack->top--;
    stack->size--;
    return temp;
}

char *peek(Stack *stack) {
    if (isEmpty(stack)) {
        return NULL;
    }

    return stack->data[stack->top];
}

int search(Stack *stack, char *data) {
    if (isEmpty(stack)) {
        return -1;
    }
    int popCount = 1;
    for (int i = stack->top; i >= 0; i--) {
        if (strcmp(stack->data[i], data) == 0) {
            return popCount;
        }
        popCount++;
    }
    return -1;
}

void printAll(Stack *stack) {
    printf("=> stack size: %d\n", stack->size);
    int size = stack->size - 1;
    printf("   │ %6s │ <-- top\n", peek(stack));

    while (size--) {
        printf("   │ %6s │\n", stack->data[size]);
    }
    printf("   └─────────┘\n");
}