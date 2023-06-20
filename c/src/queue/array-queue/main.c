#include "array-queue.h"

int main() {
    Queue queue = {0};

    initQueue(&queue);

    if (isEmpty(&queue)) {
        printf("queue is empty\n");
    } else {
        printf("queue was not empty\n");
    }

    enqueue(&queue, "TEST 01");
    enqueue(&queue, "TEST 02");
    enqueue(&queue, "TEST 03");
    enqueue(&queue, "TEST 04");
    enqueue(&queue, "TEST 05");
    printAll(&queue);

    if (isFull(&queue)) {
        printf("queue is full\n");
    } else {
        printf("queue was not full\n");
    }

    printf("dequeue(): %s\n", dequeue(&queue));
    printAll(&queue);

    printf("peek(): %s\n", peek(&queue));
    printf("search(\"TEST 03\"): %d\n", search(&queue, "TEST 03"));

    printf("dequeue(): %s\n", dequeue(&queue));
    printf("dequeue(): %s\n", dequeue(&queue));
    printf("dequeue(): %s\n", dequeue(&queue));
    printf("dequeue(): %s\n", dequeue(&queue));
    printAll(&queue);

    enqueue(&queue, "TEST 01");
    enqueue(&queue, "TEST 02");
    enqueue(&queue, "TEST 03");
    enqueue(&queue, "TEST 04");
    printAll(&queue);
    printf("search(\"TEST 03\"): %d\n", search(&queue, "TEST 03"));

    return 0;
}