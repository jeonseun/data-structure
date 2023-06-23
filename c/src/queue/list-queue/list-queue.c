#include "list-queue.h"

static Node *createNode(char *data) {
    Node *newNode = (Node *) malloc(sizeof(Node));

    size_t len = strlen(data) + 1;
    newNode->data = (char *) malloc(len);
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

void initQueue(Queue *queue) {
    Node  *dummyFront = createNode("Dummy Front");
    Node  *dummyRear = createNode("Dummy Rear");

    dummyFront->next = dummyRear;
    dummyRear->prev = dummyFront;

    queue->front = dummyFront;
    queue->rear = dummyRear;
    queue->size = 0;
}

int isEmpty(Queue *queue) {
    return queue->size == 0;
}

int enqueue(Queue *queue, char *data) {
    Node *newNode = createNode(data);

    // 더미 rear 노드의 앞 노드, 즉 실질적인 rear
    Node *realRear = queue->rear->prev;

    newNode->prev = realRear;
    newNode->next = queue->rear;

    realRear->next = newNode;
    queue->rear->prev = newNode;

    return ++queue->size;
}

char *dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        return NULL;
    }

    // 더미 front 노드의 다음 노드, 즉 실질적인 front
    Node *realFront = queue->front->next;
    char *data = realFront->data;

    queue->front->next = realFront->next;
    realFront->next->prev = queue->front;
    free(realFront);
    queue->size--;
    return data;
}

char *peek(Queue *queue) {
    if (isEmpty(queue)) {
        return NULL;
    }

    return queue->front->next->data;
}

int search(Queue *queue, char *target) {
    if (isEmpty(queue)) {
        return -1;
    }
    int order = 1;

    Node *realFront = queue->front->next;
    Node *realRear = queue->rear->prev;

    Node *cur = realFront;
    while (cur != realRear) {
        if (strcmp(cur->data, target) == 0) {
            return order;
        }
        cur = cur->next;
        order++;
    }

    return -1;
}

void printAll(Queue *queue) {
    printf("=> queue size: %d\n", queue->size);
    printf("  front <- [%s] ", queue->front->data);

    Node *cur = queue->front->next;

    while (cur != queue->rear) {
        printf("[%s] ", cur->data);
        cur = cur->next;
    }

    printf("[%s] -> rear\n", queue->rear->data);
}