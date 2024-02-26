cmake_minimum_required(VERSION 3.27)
project(drom C)

set(CMAKE_C_STANDARD 11)

add_executable(drom main.c
        account.h
        LinkList.h
        LinkList.c
        account.c)
