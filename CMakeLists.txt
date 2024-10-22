cmake_minimum_required(VERSION 3.10)

project(DoublyLinkedList)
set(DOUBLY_LINKED_LIST_SRC main.cpp DoublyLinkedList.cpp)
set(DOUBLY_LINKED_LIST_HDR DoublyLinkedList.hpp)
add_executable(${PROJECT_NAME} ${DOUBLY_LINKED_LIST_SRC} ${DOUBLY_LINKED_LIST_HDR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

#file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/data.dat
#     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
