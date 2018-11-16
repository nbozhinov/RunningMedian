cmake_minimum_required(VERSION 3.0)

project(running_median)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_library(running_median INTERFACE)
target_include_directories(running_median INTERFACE include)

# Needed for code coverage reporting
if(ENABLE_COVERAGE)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -pthread -g -O0 -fprofile-arcs -ftest-coverage")
endif()

# Enable testing for the project
enable_testing()
add_subdirectory(tests)
