cmake_minimum_required(VERSION 3.17)
project(Lesson1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lesson1 main.cpp Lesson.cpp Person.cpp PhoneNumber.cpp PhoneBook.cpp)
