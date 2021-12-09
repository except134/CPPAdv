cmake_minimum_required(VERSION 3.17)
project(Lesson1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lesson1 main.cpp Lesson.cpp Person.cpp PhoneNumber.cpp PhoneBook.cpp)
