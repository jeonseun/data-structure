#include "list-stack.h"

void initStack(Stack *stack) {
    stack->top = (Node *) malloc(sizeof(Node));
    stack->top->next = NULL;
    strcpy(stack->top->data, "Dummy Top");
    stack->size = 0;
}

int isEmpty(Stack *stack) {
    return stack->size == 0;
}

static Node *createNode(char *data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

int push(Stack *stack, char *data) {
    Node *newNode = createNode(data);

    newNode->next = stack->top->next;
    stack->top->next = newNode;

    return ++stack->size;
}

char *pop(Stack *stack) {
    if (isEmpty(stack)) {
        return NULL;
    }

    // 스택에 데이터 복사본 반환 및 해당 데이터 메모리 해제
    char *temp = (char *) malloc(sizeof(char) * strlen(stack->top->next->data));
    strcpy(temp, stack->top->next->data);

    Node *del = stack->top->next;
    stack->top->next = del->next;
    free(del);
    stack->size--;
    return temp;
}

char *peek(Stack *stack) {
    if (isEmpty(stack)) {
        return NULL;
    }

    return stack->top->next->data;
}

int search(Stack *stack, char *target) {
    if (isEmpty(stack)) {
        return -1;
    }

    int popCount = 1;

    Node *cur = stack->top->next;

    while (cur != NULL) {
        if (strcmp(cur->data, target) == 0) {
            return popCount;
        }
        popCount++;
        cur = cur->next;
    }

    return -1;
}

void printAll(Stack *stack) {
    printf("=> stack size: %d\n", stack->size);
    printf("   │ %10s │ <-- top\n", peek(stack));

    Node *cur = stack->top->next;
    while (cur != NULL) {
        printf("   │ %10s │\n", cur->data);
        cur = cur->next;
    }
    printf("   └────────────┘\n");
}