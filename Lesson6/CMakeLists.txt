cmake_minimum_required(VERSION 3.17)
project(Lesson6)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS " -pthread ${CMAKE_CXX_FLAGS}" )

add_executable(Lesson6 main.cpp Lesson.cpp)
