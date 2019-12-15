cmake_minimum_required(VERSION 3.15)
project(newton)

set(CMAKE_CXX_STANDARD 14)

add_executable(newton main.cpp head.h Function.cpp Function.h Complex.cpp Complex.h ComplexFunction.cpp ComplexFunction.h draw.cpp)

target_link_libraries(newton -lsfml-graphics -lsfml-window -lsfml-system)