cmake_minimum_required(VERSION 3.6)

set(PROJECT_NAME CHESS)
project(${PROJECT_NAME})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

include_directories(
./src
)

set(SOURCE_FILES  ./src/main.cpp ./src/figure.cpp ./src/field.cpp ./src/UI.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
