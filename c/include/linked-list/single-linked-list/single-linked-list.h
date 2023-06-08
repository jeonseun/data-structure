#ifndef C_SINGLE_LINKED_LIST_H
#define C_SINGLE_LINKED_LIST_H
#define HEAD_MSG "Dummy Head"
#define TAIL_MSG "Dummy Tail"

/**
 * 리스트 구성 요소 노드
 */
typedef struct Node {
    char data[20];
    struct Node *next;
} Node;

/**
 * 리스트 시작 노드와 끝 노드에 대한 포인터 head, tail을 가지며 각각은 더미 노드에 해당한다. 또한 리스트 내의 더미 노드를 제외한 노드의 개수를 저장하는 size 노드를 가진다.
 */
typedef struct List {
    Node *head;
    Node *tail;
    int size;
} List;

/**
 * 리스트를 초기화한다. 이 과정에서 head, tail에 대한 더미 노드 세팅이 일어나며 size의 값이 0으로 설정된다.
 * @param list 초기화 대상 리스트 포인터
 */
void initList(List *list);

/**
 * 리스트의 모든 노드를 출력한다.
 * @param list 출력 대상 리스트 포인터
 */
void printAll(List *list);

/**
 * 신규 노드를 생성한다.
 * @param data 새 노드가 저장할 값
 * @return 생성된 노드에 대한 포인터
 */
static Node *createNode(char *data);

/**
 * 특정 노드 뒤에 새 노드를 추가한다.
 * @param target 대상 노드 포인터
 * @param newNode 추가할 노드 포인터
 */
static void insertAfter(Node *target, Node *newNode);

/**
 * 특정 값을 가지는 노드를 찾는다.
 * @param head 리스트 head 노드 포인터
 * @param data 찾는 노드의 값
 * @return 노드 포인터: 찾은 경우, NULL: 못 찾은 경우
 */
static Node *findNode(Node *head, char *data);

/**
 * 특정 값을 가지는 노드의 직전 노드를 찾는다.
 * @param head 리스트 head 노드 포인터
 * @param data 찾는 노드 바로 다음 노드의 값
 * @return 노드 포인터: 찾은 경우, NULL: 못 찾은 경우
 */
static Node *findPrevNode(Node *head, char *data);

/**
 * 리스트 맨 앞에 노드를 추가한다.
 * @param list 대상 리스트 포인터
 * @param data 추가할 노드 값
 * @return 현재 리스트 노드 개수
 */
int insertAtHead(List *list, char *data);

/**
 * 리스트 맨 뒤에 노드를 추가한다.
 * @param list 대상 리스트 포인터
 * @param data 추가할 노드 값
 * @return 현재 리스트 노드 개수
 */
int insertAtTail(List *list, char *data);

/**
 * 리스트의 특정 값을 가지는 노드 뒤에 노드를 추가한다.
 * @param list 대상 리스트 포인터
 * @param target 찾을 노드의 값
 * @param data 추가할 노드의 값
 * @return 현재 리스트 노드 개수
 */
int insertAtTarget(List *list, char *target, char *data);

/**
 * 리스트의 특정 노드를 제거한다.
 * @param list 대상 리스트
 * @param target 삭제 대상 노드의 값
 * @return 0: 삭제 성공, -1: 삭제 실패
 */
int delete(List *list, char *target);

/**
 * 리스트의 모든 노드를 제거하여 빈 리스트로 만든다.
 * @param list 대상 리스트
 */
void clear(List *list);

/**
 * 리스트의 모든 자원을 반환한다.
 * @param list 대상 리스트
 */
void release(List *list);

/**
 * 리스트에서 더미 노드를 제외한 현재 노드 개수를 반환한다.
 * @param list 대상 리스트
 * @return 리스트의 노드 개수
 */
int getSize(List *list);
#endif //C_SINGLE_LINKED_LIST_H
