#ifndef C_ARRAY_STACK_H
#define C_ARRAY_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 10

typedef struct Stack {
    int data[STACK_SIZE];
    int top;
    int size;
} Stack;

/**
 * 스택을 초기화한다.
 * @param stack 초기화 대상 스택 포인터
 */
void initStack(Stack *stack);

/**
 * 스택이 가득차있는지 확인한다.
 * @param stack 대상 스택 포인터
 * @return 스택이 가득찬 경우 1, 공간이 있는 경우 0
 */
int isFull(Stack *stack);

/**
 * 스택에 데이터를 추가한다.
 * @param stack 대상 스택 포인터
 * @param data 추가할 데이터
 * @return 스택이 가득찬 경우 -1 이외의 경우는 데이터를 추가한 뒤 스택의 크기
 */
int push(Stack *stack, int data);

/**
 * 스택이 비어있는지 확인한다.
 * @param stack 대상 스택 포인터
 * @return 스택이 빈 경우 1, 데이터가 있는 경우 0
 */
int isEmpty(Stack *stack);

/**
 * 스택의 데이터를 제거한다.
 * @param stack 대상 스택 포인터
 * @return 스택이 빈 경우 -1 이외의 경우는 스택의 최상단에 있는 데이터
 */
int pop(Stack *stack);

/**
 * 스택 최상단의 데이터를 반환한다.
 * @param stack 대상 스택 포인터
 * @return 스택이 빈 경우 -1 이외의 경우는 스택의 최상단에 있는 데이터
 */
int peek(Stack *stack);

/**
 * 스택에 특정 데이터가 있는지 확인한다.
 * @param stack 대상 스택 포인터
 * @param data 대상 데이터
 * @return 스택에 해당 데이터가 없는경우 -1 있는 경우 top 기준으로 해당 데이터가 있는 위치
 */
int search(Stack *stack, int data);

/**
 * 스택의 모든 요소를 출력한다.
 * @param stack 대상 스택 포인터
 */
void printAll(Stack *stack);
#endif //C_ARRAY_STACK_H
