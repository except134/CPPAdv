cmake_minimum_required(VERSION 3.17)
project(Lesson7)

set(CMAKE_CXX_STANDARD 20)

include(FindProtobuf)
find_package(Protobuf REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIR})

protobuf_generate_cpp(PROTO_SRC PROTO_HEADER proto/Lesson7Proto.proto)
add_library(proto ${PROTO_HEADER} ${PROTO_SRC})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_executable(${PROJECT_NAME} main.cpp Lesson.cpp)
target_link_libraries(${PROJECT_NAME} proto ${PROTOBUF_LIBRARIES})
