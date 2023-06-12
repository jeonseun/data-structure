#include <stdio.h>
#include "single-linked-list.h"

int main() {
    List list = {0};
    initList(&list);
    // 빈 리스트 출력
    printAll(&list);

    // 리스트 맨 앞에 추가
    insertAtHead(&list, "TEST 1");
    insertAtHead(&list, "TEST 2");
    insertAtHead(&list, "TEST 3");
    printAll(&list);
    clear(&list);

    // 리스트 맨 뒤에 추가
    insertAtTail(&list, "TEST 1");
    insertAtTail(&list, "TEST 2");
    insertAtTail(&list, "TEST 3");
    printAll(&list);


    // 리스트 특정 노드 삭제
    if (delete(&list, "TEST 3") == -1) {
        printf("노드 삭제 실패\n");
    }
    printAll(&list);

    // 리스트 특정 노드 검색
    int idx;
    if ((idx = search(&list, "TEST 1")) != -1) {
        printf("해당 노드 인덱스 %d\n", idx);
    } else {
        printf("검색 실패\n");
    }

    // 리스트 특정 노드 추출
    printf("getAt(): %s\n", getAt(&list, idx));
    return 0;
}
