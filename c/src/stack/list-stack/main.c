#include <stdio.h>
#include "list-stack.h"

int main() {
    Stack stack = {0};
    initStack(&stack);

    if (isEmpty(&stack)) {
        printf("isEmpty(): true\n");
    } else {
        printf("isEmpty(): false\n");
    }

    push(&stack, "TEST 01");
    push(&stack, "TEST 02");
    push(&stack, "TEST 03");
    push(&stack, "TEST 04");
    push(&stack, "TEST 05");

    printf("peek(): %s\n", peek(&stack));

    for (int i = 0; i < 6; i++) {
        char *popData = pop(&stack);
        if (popData == NULL) {
            printf("pop(): stack is empty\n");
        } else {
            printf("pop(): %s\n", popData);
        }
    }
    printf("peek(): %s\n", peek(&stack));

    push(&stack, "TEST 01");
    push(&stack, "TEST 02");
    push(&stack, "TEST 03");
    push(&stack, "TEST 04");
    push(&stack, "TEST 05");

    printf("search(\"TEST 01\"): %d\n", search(&stack, "TEST 01"));
    printAll(&stack);
    return 0;
}