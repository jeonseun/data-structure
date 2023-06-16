#ifndef C_SINGLE_LINKED_LIST_H
#define C_SINGLE_LINKED_LIST_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data[20];
    struct Node *next; // 다음 노드에 대한 링크(포인터)
} Node;

typedef struct List {
    Node *head; // 리스트 시작 노드에 대한 링크(포인터)
    int size;
} List;

/**
 * 연결 리스트를 초기화한다.
 * @param list 초기화 대상 리스트 포인터
 */
void initList(List *list);

/**
 * 연결 리스트를 순회하며 모든 노드를 출력한다.
 * @param list 순회 대상 리스트 포인터
 */
void printAll(List *list);

static Node *createNode(char *data);

static void link(Node *target, Node *newNode);

/**
 * 연결 리스트 맨 앞에 노드를 추가한다.
 * @param list 대상 리스트 포인터
 * @param data 추가할 데이터
 * @return 노드를 추가한 후 연결 리스트의 크기
 */
int insertAtHead(List *list, char *data);

/**
 * 연결 리스트 맨 뒤에 노드를 추가한다.
 * @param list 대상 리스트 포인터
 * @param data 추가할 데이터
 * @return 노드를 추가한 후 연결 리스트의 크기
 */
int insertAtTail(List *list, char *data);

/**
 * 연결 리스트의 특정 노드를 제거한다.
 * @param list 대상 리스트 포인터
 * @param target 삭제 대상 노드 데이터
 * @return -1: 삭제 실패, 삭제 성공 시 삭제후 리스트의 크기
 */
int delete(List *list, char *target);

/**
 * 연결 리스트의 모든 노드를 제거한다.
 * @param list 대상 리스트 포인터
 */
void clear(List *list);

/**
 * 연결 리스트의 특정 노드를 검색한다.
 * @param list 대상 리스트 포인터
 * @param target 검색 대상 노드 데이터
 * @return -1: 해당 노드가 존재하지 않음, 이외의 숫자 해당 노드의 리스트 상 순서 (0부터 시작)
 */
int search(List *list, char *target);

/**
 * 연결 리스트의 특정 노드의 데이터를 추출한다.
 * @param list 대상 리스트 포인터
 * @param idx 추출 대상 노드의 순서 (0부터 시작)
 * @return NULL: 유효하지 않은 인덱스 인경우, 데이터: 유효한 인덱스인 경우
 */
char *getAt(List *list, int idx);

#endif //C_SINGLE_LINKED_LIST_H
