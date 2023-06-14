#ifndef C_DOUBLE_LINKED_LIST_H
#define C_DOUBLE_LINKED_LIST_H

typedef struct Node {
    char data[20];
    struct Node *prev; // 직전 노드에 대한 링크(포인터)
    struct Node *next; // 다음 노드에 대한 링크(포인터)
} Node;

typedef struct List {
    Node *head;
    Node *tail;
    int size;
} List;

/**
 * 연결 리스트를 초기화한다.
 * @param list 초기화 대상 리스트 포인터
 */
void initList(List *list);

/**
 * 연결 리스트를 순방향으로 순회하며 모든 노드를 출력한다.
 * @param list 순회 대상 리스트 포인터
 */
void printAll(List *list);

/**
 * 연결 리스트를 역방향으로 순회하며 모든 노드를 출력한다.
 * @param list 순회 대상 리스트 포인터
 */
void printAllReverse(List *list);

static Node *findNode(List *list, char *data);

static Node *createNode(char *data);

static void linkBefore(Node *target, Node *newNode);

static void linkAfter(Node *target, Node *newNode);

/**
 * 연결 리스트의 맨 앞에 노드를 추가한다.
 * @param list 대상 리스트 포인터
 * @param data 추가할 노드 데이터
 * @return 추가한 후 리스트의 크기
 */
int insertAtHead(List *list, char *data);

/**
 * 연결 리스트의 맨 뒤에 노드를 추가한다.
 * @param list 대상 리스트 포인터
 * @param data 추가할 노드 데이터
 * @return 추가한 후 리스트의 크기
 */
int insertAtTail(List *list, char *data);

/**
 * 연결 리스트의 특정 노드 뒤에 노드를 추가한다.
 * @param list 대상 리스트 포인터
 * @param target 대상 노드 데이터
 * @param data 추가할 노드 데이터
 * @return 대상 노드가 없는 경우 -1 이외의 경우는 추가한 후 리스트의 크기
 */
int insertAtTarget(List *list, char *target, char *data);

/**
 * 연결 리스트의 특정 순서에 노드를 추가한다.
 * @param list 대상 리스트 포인터
 * @param idx 추가할 순서
 * @param data 추가할 노드 데이터
 * @return idx가 유효하지 않은 경우 -1 이외의 경우는 추가한 후 리스트의 크기
 */
int insertAt(List *list, int idx, char *data);

/**
 * 연결 리스트의 특정 노드를 제거한다.
 * @param list 대상 리스트 포인터
 * @param target 제거할 노드 데이터
 * @return 대상이 없는 경우 -1 이외의 경우에는 제거한 후 리스트의 크기
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
#endif //C_DOUBLE_LINKED_LIST_H
