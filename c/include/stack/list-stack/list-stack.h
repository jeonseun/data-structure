#ifndef C_LIST_STACK_H
#define C_LIST_STACK_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    char data[20];
    struct Node *next;
} Node;

typedef struct Stack {
    Node *top;
    int size;
} Stack;

/**
 * 스택을 초기화한다.
 * @param stack 초기화 대상 스택 포인터
 */
void initStack(Stack *stack);

/**
 * 스택에 데이터를 추가한다.
 * @param stack 대상 스택 포인터
 * @param data 추가할 데이터
 * @return 데이터를 추가한 뒤 스택의 크기
 */
int push(Stack *stack, char *data);

/**
 * 스택이 비어있는지 확인한다.
 * @param stack 대상 스택 포인터
 * @return 스택이 빈 경우 1, 데이터가 있는 경우 0
 */
int isEmpty(Stack *stack);

/**
 * 스택의 데이터를 제거한다.
 * @param stack 대상 스택 포인터
 * @return 스택이 빈 경우 NULL 이외의 경우는 스택의 최상단에 있는 데이터
 */
char *pop(Stack *stack);

/**
 * 스택 최상단의 데이터를 반환한다.
 * @param stack 대상 스택 포인터
 * @return 스택이 빈 경우 NULL 이외의 경우는 스택의 최상단에 있는 데이터
 */
char *peek(Stack *stack);

/**
 * 스택에 특정 데이터가 있는지 확인한다.
 * @param stack 대상 스택 포인터
 * @param data 대상 데이터
 * @return 스택에 해당 데이터가 없는경우 -1 있는 경우 top 기준으로 해당 데이터가 있는 위치
 */
int search(Stack *stack, char *target);


/**
 * 스택의 모든 요소를 출력한다.
 * @param stack 대상 스택 포인터
 */
void printAll(Stack *stack);

#endif //C_LIST_STACK_H

