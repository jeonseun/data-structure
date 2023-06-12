#include "single-linked-list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initList(List *list) {
    // 더미 노드 할당 및 값 초기화
    list->head = (Node *) malloc(sizeof(Node));
    strcpy(list->head->data, "Dummy Head");
    list->head->next = NULL;

    // 리스트 사이즈 초기화
    list->size = 0;
}

void printAll(List *list) {
    Node *cur = list->head;
    printf("=> print list: size: %d\n", list->size);
    int i = 0;
    while (cur != NULL) {
        printf("  [NO: %d ] cur: [%p] data: [%10s] next: [%p]\n", i, cur, cur->data, cur->next);
        cur = cur->next;
        i++;
    }

    putchar('\n');
}

static Node *createNode(char *data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

static void link(Node *target, Node *newNode) {
    newNode->next = target->next;
    target->next = newNode;
}

int insertAtHead(List *list, char *data) {
    Node *newNode = createNode(data);
    link(list->head, newNode);
    return ++list->size;
}

int insertAtTail(List *list, char *data) {
    Node *newNode = createNode(data);

    Node *cur = list->head;

    while (cur->next != NULL) {
        cur = cur->next;
    }

    link(cur, newNode);
    return ++list->size;
}

int delete(List *list, char *target) {

    Node *cur = list->head;

    while (cur->next != NULL) {
        if (strcmp(cur->next->data, target) == 0) {
            Node *targetPrev = cur;
            Node *targetNode = cur->next;
            Node *targetNext = cur->next->next;
            targetPrev->next = targetNext;
            free(targetNode);
            return --list->size;
        }
        cur = cur->next;
    }

    return -1;
}

void clear(List *list) {
    Node *cur = list->head->next;

    while (cur != NULL) {
        Node *del = cur;
        cur = cur->next;
        free(del);
    }
    list->head->next = NULL;
    list->size = 0;
}

int search(List *list, char *target) {
    Node *cur = list->head->next;

    int idx = 0;
    while (cur != NULL) {
        if (strcmp(cur->data, target) == 0) {
            return idx;
        }
        idx++;
        cur = cur->next;
    }

    return -1;
}

char *getAt(List *list, int idx) {
    // 유효하지 않은 인덱스 검사
    if (idx < 0 || idx > list->size) {
        return NULL;
    }

    Node *cur = list->head->next;

    for (int i = 0; i < idx; i++) {
        cur = cur->next;
    }

    return cur->data;
}