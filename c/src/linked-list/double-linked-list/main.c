#include <stdio.h>
#include "double-linked-list.h"

int main() {
    List list = {0};
    initList(&list);
    printAll(&list);
    printAllReverse(&list);

    insertAtHead(&list, "TEST 01");
    insertAtHead(&list, "TEST 02");
    insertAtHead(&list, "TEST 03");
    insertAtHead(&list, "TEST 04");
    printAll(&list);
    printAllReverse(&list);
    clear(&list);

    insertAtTail(&list, "TEST 01");
    insertAtTail(&list, "TEST 02");
    insertAtTail(&list, "TEST 03");
    insertAtTail(&list, "TEST 04");
    printAll(&list);

    if (insertAtTarget(&list, "TEST 0", "TEST 05") == -1) {
        printf("target node not found\n");
    }
    printAll(&list);

    if (insertAt(&list, 4, "TEST 00") == -1) {
        printf("invalid idx\n");
    }
    printAll(&list);

    if (delete(&list, "TEST 04") == -1) {
        printf("delete target not found\n");
    }
    printAll(&list);

    clear(&list);
    printAll(&list);

    int idx;
    if ((idx = search(&list, "TEST 04")) != -1) {
        printf("find node idx: %d\n", idx);
    } else {
        printf("search fail\n");
    }

    return 0;
}

