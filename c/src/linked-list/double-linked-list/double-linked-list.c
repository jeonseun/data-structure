#include "double-linked-list.h"

void initList(List *list) {
    // 더미 노드 할당 및 초기화
    list->head = (Node *) malloc(sizeof(Node));
    memset(list->head, 0, sizeof(Node));
    strcpy(list->head->data, "Dummy Head");

    list->tail = (Node *) malloc(sizeof(Node));
    memset(list->tail, 0, sizeof(Node));
    strcpy(list->tail->data, "Dummy Tail");

    // 더미 헤드와 더미 테일 연결
    list->head->next = list->tail;
    list->tail->prev = list->head;

    // 리스트 사이즈 초기화
    list->size = 0;
}

void printAll(List *list) {
    Node *cur = list->head;

    printf("=> print list: size: %d\n", list->size);
    int i = 0;
    while (cur != NULL) {
        printf("  [NO: %d] cur: [%p] prev: [%-14p] data: [%10s] next: [%-14p]\n", i, cur, cur->prev, cur->data, cur->next);
        cur = cur->next;
        i++;
    }

    putchar('\n');
}

void printAllReverse(List *list) {
    Node *cur = list->tail;

    printf("=> print list reverse: size: %d\n", list->size);
    int i = 0;
    while (cur != NULL) {
        printf("  [NO: %d] cur: [%p] prev: [%-14p] data: [%10s] next: [%-14p]\n", i, cur, cur->prev, cur->data, cur->next);
        cur = cur->prev;
        i++;
    }

    putchar('\n');
}

static Node *findNode(List *list, char *data) {
    Node *cur = list->head->next;

    while (cur != list->tail) {
        if (strcmp(cur->data, data) == 0) {
            return cur;
        }
        cur = cur->next;
    }

    return NULL;
}

static Node *createNode(char *data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    memset(newNode, 0, sizeof(Node));
    strcpy(newNode->data, data);
    return newNode;
}

static void linkBefore(Node *target, Node *newNode) {
    newNode->next = target;
    newNode->prev = target->prev;

    target->prev->next = newNode;
    target->prev = newNode;
}

static void linkAfter(Node *target, Node *newNode) {
    newNode->prev = target;
    newNode->next = target->next;

    target->next->prev = newNode;
    target->next = newNode;
}

int insertAtHead(List *list, char *data) {
    linkAfter(list->head, createNode(data));
    return ++list->size;
}

int insertAtTail(List *list, char *data) {
    linkBefore(list->tail, createNode(data));
    return ++list->size;
}

int insertAtTarget(List *list, char *target, char *data) {
    Node *targetNode = findNode(list, target);

    // 대상 노드를 못 찾는 경우의 처리
    if (targetNode == NULL) {
        return -1;
    }

    linkAfter(targetNode, createNode(data));
    return ++list->size;
}

int insertAt(List *list, int idx, char *data) {
    // idx 유효성 검사
    if (idx < 0 || idx >= list->size) {
        return -1;
    }

    Node *cur = list->head->next;

    for (int i = 0; i < idx; i++) {
        cur = cur->next;
    }

    linkBefore(cur, createNode(data));
    return ++list->size;
}

int delete(List *list, char *target) {
    Node *targetNode = findNode(list, target);

    // 삭제 대상 노드가 없는 경우의 처리
    if (targetNode == NULL) {
        return -1;
    }

    Node *prevNode = targetNode->prev;
    Node *nextNode = targetNode->next;

    prevNode->next = nextNode;
    nextNode->prev = prevNode;
    return --list->size;
}

void clear(List *list) {
    Node *cur = list->head->next;

    while (cur != list->tail) {
        Node *del = cur;
        cur = cur->next;
        free(del);
    }

    list->head->next = list->tail;
    list->tail->prev = list->head;
    list->size = 0;
}

int search(List *list, char *target) {
    Node *cur = list->head->next;
    int i = 0;
    while (cur != list->tail) {
        if (strcmp(cur->data, target) == 0) {
            return i;
        }
        i++;
        cur = cur->next;
    }

    return -1;
}