#include <stdio.h>
#include "single-linked-list.h"

int main() {
    List list = {0};
    initList(&list);
    // 빈 리스트 출력
    printAll(&list);

    // 리스트 헤드에 3개 추가
    insertAtHead(&list, "TEST 01");
    insertAtHead(&list, "TEST 02");
    insertAtHead(&list, "TEST 03");
    printAll(&list);
    clear(&list);

    // 리스트 테일에 3개 추가
    insertAtTail(&list, "TEST 01");
    insertAtTail(&list, "TEST 02");
    insertAtTail(&list, "TEST 03");
    printAll(&list);

    // 리스트 특정 노드 뒤에 추가
    insertAtTarget(&list, "TEST 02", "TEST 02-1");
    printAll(&list);

    // 리스트 특정 노드 제거
    delete(&list, "TEST 02-1");
    printAll(&list);

    printf("리스트 노드 개수 : %d\n", getSize(&list));

    // 리스트 자원 반환
    release(&list);
    return 0;
}
