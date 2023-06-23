#include "list-queue.h"

int main() {
    Queue queue;
    initQueue(&queue);

    enqueue(&queue, "Test 01");
    enqueue(&queue, "Test 02");
    enqueue(&queue, "Test 03");
    enqueue(&queue, "Test 04");

    if (isEmpty(&queue)) {
        printf("queue is empty\n");
    } else {
        printf("queue was not empty\n");
    }

    printf("queue size: %d\n", queue.size);

//    printf("dequeue(): %s\n", dequeue(&queue));
//    printf("dequeue(): %s\n", dequeue(&queue));
//    printf("dequeue(): %s\n", dequeue(&queue));
//    printf("dequeue(): %s\n", dequeue(&queue));
//    printf("dequeue(): %s\n", dequeue(&queue));

    printf("search(\"Test 01\"): %d\n", search(&queue, "Test 02"));
    printAll(&queue);
    return 0;
}