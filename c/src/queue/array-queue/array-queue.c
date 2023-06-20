#include "array-queue.h"

void initQueue(Queue *queue) {
    queue->front = 0;
    queue->rear = 0;
    queue->size = 0;
}

int isFull(Queue *queue) {
    return queue->size == QUEUE_SIZE;
}

int enqueue(Queue *queue, char *data) {
    if (isFull(queue)) {
        return -1;
    }

    size_t length = strlen(data) + 1;
    queue->data[queue->rear] = (char *) malloc(length);
    strcpy(queue->data[queue->rear], data);
    queue->rear++;
    queue->rear %= QUEUE_SIZE;
    return ++queue->size;
}

int isEmpty(Queue *queue) {
    return queue->size == 0;
}

char *dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        return NULL;
    }

    // 큐의 front 데이터를 메모리 해제하고 복사본 반환
    size_t length = strlen(queue->data[queue->front]) + 1;
    char *temp = (char *) malloc(length);
    strcpy(temp, queue->data[queue->front]);
    free(queue->data[queue->front]);
    queue->front++;
    queue->front %= QUEUE_SIZE;
    queue->size--;
    return temp;
}

char *peek(Queue *queue) {
    if (isEmpty(queue)) {
        return NULL;
    }
    return queue->data[queue->front];
}

int search(Queue *queue, char *target) {
    if (isEmpty(queue)) {
        return -1;
    }

    int order = 1;
    int size = queue->size;
    int cur = queue->front;

    while (size--) {
        if (strcmp(queue->data[cur], target) == 0) {
            return order;
        }
        order++;
        cur = (cur + 1) % QUEUE_SIZE;
    }

    return -1;
}

void printAll(Queue *queue) {
    printf("=> queue size: %d\n", queue->size);

    printf("  front <== ");

    int size = queue->size;
    int cur = queue->front;
    while (size--) {
        printf("[%6s] ", queue->data[cur]);
        cur = (cur + 1) % QUEUE_SIZE;
    }

    printf(" ==> rear\n");
}