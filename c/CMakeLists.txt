cmake_minimum_required(VERSION 3.25)
project(c C)

set(CMAKE_C_STANDARD 11)

# 연결 리스트 헤더/소스 파일 상위 경로
set(LL_HEADERS include/linked-list)
set(LL_SOURCES src/linked-list)

# 단일 연결 리스트 헤더, 소스 파일
set(SLL_HEADER_PATH ${LL_HEADERS}/single-linked-list)
set(SLL_SOURCE_FILE ${LL_SOURCES}/single-linked-list/single-linked-list.c)

# 이중 연결 리스트 헤더, 소스 파일
set(DLL_HEADER_PATH ${LL_HEADERS}/double-linked-list)
set(DLL_SOURCE_FILE ${LL_SOURCES}/double-linked-list/double-linked-list.c)

# 스택 헤더/소스 파일 상위 경로
set(STACK_HEADERS include/stack)
set(STACK_SOURCES src/stack)

# 배열 스택 헤더, 소스 파일
set(ARRAY_STACK_HEADER_PATH ${STACK_HEADERS}/array-stack)
set(ARRAY_STACK_SOURCE_FILE ${STACK_SOURCES}/array-stack/array-stack.c)

# 리스트 스택 헤더, 소스 파일
set(LIST_STACK_HEADER_PATH ${STACK_HEADERS}/list-stack)
set(LIST_STACK_SOURCE_FILE ${STACK_SOURCES}/list-stack/list-stack.c)

# 큐 헤더/소스 파일 상위 경로
set(QUEUE_HEADERS include/queue)
set(QUEUE_SOURCES src/queue)

# 배열 큐 헤더, 소스 파일
set(ARRAY_QUEUE_HEADER_PATH ${QUEUE_HEADERS}/array-queue)
set(ARRAY_QUEUE_SOURCE_FILE ${QUEUE_SOURCES}/array-queue/array-queue.c)

# 리스트 큐 헤더, 소스 파일
set(LIST_QUEUE_HEADER_PATH ${QUEUE_HEADERS}/list-queue)
set(LIST_QUEUE_SOURCE_FILE ${QUEUE_SOURCES}/list-queue/list-queue.c)

include_directories(
        ${SLL_HEADER_PATH}
        ${DLL_HEADER_PATH}
        ${ARRAY_STACK_HEADER_PATH}
        ${LIST_STACK_HEADER_PATH}
        ${ARRAY_QUEUE_HEADER_PATH}
        ${LIST_QUEUE_HEADER_PATH}
)

# 연결 리스트 테스트 소스 파일
add_executable(main-sll src/linked-list/single-linked-list/main.c ${SLL_SOURCE_FILE})
add_executable(main-dll src/linked-list/double-linked-list/main.c ${DLL_SOURCE_FILE})

# 스택 테스트 소스 파일
add_executable(main-array-stack src/stack/array-stack/main.c ${ARRAY_STACK_SOURCE_FILE})
add_executable(main-list-stack src/stack/list-stack/main.c ${LIST_STACK_SOURCE_FILE})

# 큐 테스트 소스 파일
add_executable(main-array-queue src/queue/array-queue/main.c ${ARRAY_QUEUE_SOURCE_FILE})
add_executable(main-list-queue src/queue/list-queue/main.c ${LIST_QUEUE_SOURCE_FILE})
