cmake_minimum_required(VERSION 3.25)
project(c C)

set(CMAKE_C_STANDARD 11)

# 연결 리스트 헤더 상위 경로
set(SLL_HEADERS include/linked-list)
# 연결 리스트 소스 파일 상위 경로
set(SLL_SOURCES src/linked-list)

# 단일 연결 리스트 헤더, 소스 파일
set(SLL_HEADER_PATH ${SLL_HEADERS}/single-linked-list)
set(SLL_SOURCE_FILE ${SLL_SOURCES}/single-linked-list/single-linked-list.c)

include_directories(${SLL_HEADER_PATH})

add_executable(main src/linked-list/single-linked-list/main.c ${SLL_SOURCE_FILE})