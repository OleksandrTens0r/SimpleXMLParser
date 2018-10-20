cmake_minimum_required(VERSION 3.12)
project(untitled)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

add_executable(untitled Parser.cpp Parser.h Exception.cpp Exception.h Test/test.cpp)
target_link_libraries(untitled gtest gtest_main)
