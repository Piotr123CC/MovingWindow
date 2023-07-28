cmake_minimum_required(VERSION 3.10)

project(MovingWindow)

set(CMAKE_C_STANDARD 99)


include_directories(${CMAKE_SOURCE_DIR}
                    Inc
                    Src
                    )

set(SRC
    ${CMAKE_SOURCE_DIR}/Src/main.c
    ${CMAKE_SOURCE_DIR}/Src/file.c
    ${CMAKE_SOURCE_DIR}/Src/queue.c
    ${CMAKE_SOURCE_DIR}/Src/algorithms.c)

set(INCLUDES
    ${CMAKE_SOURCE_DIR}/Inc/file.h
    ${CMAKE_SOURCE_DIR}/Inc/queue.h
    ${CMAKE_SOURCE_DIR}/Inc/algorithms.h
    )

add_executable(${PROJECT_NAME} ${SRC} ${INCLUDES})