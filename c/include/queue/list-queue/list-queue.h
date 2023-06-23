#ifndef C_LIST_QUEUE_H
#define C_LIST_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *data;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear;
    int size;
} Queue;

/**
 * 큐를 초기화한다.
 * @param queue 큐 포인터
 */
void initQueue(Queue *queue);

/**
 * 큐에 새 데이터를 넣는다.
 * @param queue 큐 포인터
 * @return 삽입 후 큐에 있는 데이터 개수
 */
int enqueue(Queue *queue, char *data);


/**
 * 큐가 비어있는지 확인한다.
 * @param queue 큐 포인터
 * @return 1: 큐가 비어있음, 2: 큐에 데이터가 있음
 */
int isEmpty(Queue *queue);

/**
 * 큐에 가장 먼저 들어온 데이터를 제거한다.
 * @param queue 큐 포인터
 * @return 큐에 데이터가 있는 경우 가장 먼저 들어온 데이터, 없는 경우 NULL
 */
char *dequeue(Queue *queue);

/**
 * 큐에 가장 먼저 들어온 데이터를 확인한다.
 * @param queue 큐 포인터
 * @return 큐가 빈 경우 NULL 아닌 경우 큐의 front 데이터
 */
char *peek(Queue *queue);

/**
 * 큐에 특정 데이터가 있는지 확인한다.
 * @param queue 큐 포인터
 * @param target 검색 대상
 * @return 큐가 빈 경우 -1 이외의 경우는 해당 데이터의 큐에서 순서, 즉 데이터를 얻기위해 dequeue 해야하는 횟수
 */
int search(Queue *queue, char *target);

/**
 * 큐의 모든 데이터를 출력한다.
 * @param queue 대상 큐 포인터
 */
void printAll(Queue *queue);

#endif //C_LIST_QUEUE_H