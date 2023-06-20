#ifndef C_ARRAY_QUEUE_H
#define C_ARRAY_QUEUE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define QUEUE_SIZE 5

typedef struct Queue {
    char *data[QUEUE_SIZE];
    int front;
    int rear;
    int size;
} Queue;

/**
 * 큐를 초기화한다.
 * @param queue 대상 큐 포인터
 */
void initQueue(Queue *queue);

/**
 * 큐가 가득차있는지 확인한다.
 * @param queue 대상 큐 포인터
 * @return 가득찬 경우 1, 공간이 있는 경우 0
 */
int isFull(Queue *queue);

/**
 * 큐에 새 데이터를 넣는다.
 * @param queue 대상 큐 포인터
 * @param data 추가할 데이터
 * @return 큐가 가득찬 경우 -1 이외의 경우는 데이터를 추가한 이후 큐의 크기
 */
int enqueue(Queue *queue, char *data);

/**
 * 큐가 비어있는지 확인하다.
 * @param queue 대상 큐 포인터
 * @return 비어있는 경우 1, 데이터가 있는 경우 0
 */
int isEmpty(Queue *queue);

/**
 * 큐에 가장 먼저 들어온 데이터를 제거한다.
 * @param queue 대상 큐 포인터
 * @return 큐가 빈 경우 NULL 아닌 경우 큐의 front에 위치하는 데이터
 */
char *dequeue(Queue *queue);

/**
 * 큐에 가장 먼저 들어온 데이터를 확인한다.
 * @param queue 대상 큐 포인터
 * @return 큐가 빈 경우 NULL 아닌 경우 큐의 front에 위치하는 데이터
 */
char *peek(Queue *queue);

/**
 * 큐에 특정 데이터가 있는지 확인한다.
 * @param queue 대상 큐 포인터
 * @param target 찾으려는 데이터
 * @return 큐가 빈 경우 -1 이외의 경우는 해당 데이터의 큐에서 순서, 즉 데이터를 얻기위해 dequeue 해야하는 횟수
 */
int search(Queue *queue, char *target);

/**
 * 큐의 모든 데이터를 출력한다.
 * @param queue 대상 큐 포인터
 */
void printAll(Queue *queue);

#endif //C_ARRAY_QUEUE_H
