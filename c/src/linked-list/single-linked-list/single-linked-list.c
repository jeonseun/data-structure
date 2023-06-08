#include "single-linked-list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initList(List *list) {
    list->head = (Node *) malloc(sizeof(Node));
    list->tail = (Node *) malloc(sizeof(Node));
    list->size = 0;

    memset(list->head, 0 , sizeof(Node));
    strcpy(list->head->data, HEAD_MSG);

    memset(list->tail, 0 , sizeof(Node));
    strcpy(list->tail->data, TAIL_MSG);

    list->head->next = list->tail;
}

void printAll(List *list) {
    printf("=> single linked list print => size: [%d]\n", list->size);

    Node *cursor = list->head;

    int i = 0;
    while (cursor != NULL) {
        printf("  -> no: %d cur: [%p] data: [%s] next: [%p]\n", i, cursor, cursor->data, cursor->next);
        cursor = cursor->next;
        i++;
    }

    putchar('\n');
}

static Node *createNode(char *data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    memset(newNode, 0, sizeof(Node));
    strcpy(newNode->data, data);
    return newNode;
}

static void insertAfter(Node *target, Node *newNode) {
    newNode->next = target->next;
    target->next = newNode;
}

static Node *findNode(Node *head, char *data) {
    Node *cursor = head;

    while (cursor != NULL) {
        if (strcmp(cursor->data, data) == 0) {
            return cursor;
        }
        cursor = cursor->next;
    }

    return NULL;
}

static Node *findPrevNode(Node *head, char *data) {
    Node *cursor = head;

    while (cursor->next != NULL) {
        if (strcmp(cursor->next->data, data) == 0) {
            return cursor;
        }
        cursor = cursor->next;
    }

    return NULL;
}

int insertAtHead(List *list, char *data) {
    Node *newNode = createNode(data);
    insertAfter(list->head, newNode);
    return ++list->size;
}


int insertAtTail(List *list, char *data) {
    Node *prevNode = findPrevNode(list->head, TAIL_MSG);
    Node *newNode = createNode(data);
    insertAfter(prevNode, newNode);
    return ++list->size;
}

int insertAtTarget(List *list, char *target, char *data) {
    Node *targetNode = findNode(list->head, target);
    Node *newNode = createNode(data);
    insertAfter(targetNode, newNode);
    return ++list->size;
}

int delete(List *list, char *target) {
    Node *prevNode = findPrevNode(list->head, target);

    if (prevNode == NULL) {
        return -1;
    }

    Node *targetNode = prevNode->next;
    prevNode->next = targetNode->next;
    free(targetNode);
    list->size--;
    return 1;
}

void clear(List *list) {
    Node *cursor = list->head->next;

    while (cursor != list->tail) {
        Node *target = cursor;
        cursor = cursor->next;
        free(target);
    }

    list->head->next = list->tail;
    list->size = 0;
}

void release(List *list) {
    clear(list);
    free(list->head);
    free(list->tail);
    list->head = NULL;
    list->tail = NULL;
}

int getSize(List *list) {
    return list->size;
}