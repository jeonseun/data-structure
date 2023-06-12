cmake_minimum_required(VERSION 3.25)
project(c C)

set(CMAKE_C_STANDARD 11)

# 연결 리스트 헤더 상위 경로
set(LL_HEADERS include/linked-list)
# 연결 리스트 소스 파일 상위 경로
set(LL_SOURCES src/linked-list)

# 단일 연결 리스트 헤더, 소스 파일
set(SLL_HEADER_PATH ${LL_HEADERS}/single-linked-list)
set(SLL_SOURCE_FILE ${LL_SOURCES}/single-linked-list/single-linked-list.c)

include_directories(${SLL_HEADER_PATH})

# 단일 연결 리스트 테스트 소스 파일
add_executable(main-sll src/linked-list/single-linked-list/main.c ${SLL_SOURCE_FILE})