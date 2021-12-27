cmake_minimum_required(VERSION 3.17)
project(Lesson8)

set(CMAKE_CXX_STANDARD 20)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})

add_executable(${PROJECT_NAME} main.cpp Lesson.cpp Person.cpp PhoneNumber.cpp PhoneBook.cpp Tests.cpp)
target_link_libraries(${PROJECT_NAME} GTest::GTest GTest::Main)
