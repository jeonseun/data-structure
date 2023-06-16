#include <stdio.h>
#include "array-stack.h"

int main() {
    Stack stack;
    initStack(&stack);

    for (int i = 0; i < 10; ++i) {
        char str[10];
        sprintf(str, "TEST 0%d", i);
        push(&stack, str);
    }

    printAll(&stack);

    if (isFull(&stack)) {
        printf("isFull(): stack is full\n");
    } else {
        printf("isFull(): stack was not full\n");
    }

    if (isEmpty(&stack)) {
        printf("isEmpty(): stack is empty\n");
    } else {
        printf("isEmpty(): stack was not empty\n");
    }

    for (int i = 0; i < 3; ++i) {
        printf("pop(): %s\n", pop(&stack));
    }
    printAll(&stack);

    printf("peek(): %s\n", peek(&stack));
    printAll(&stack);

    printf("search(): %d\n", search(&stack, "TEST 00"));
    return 0;
}