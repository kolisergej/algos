cmake_minimum_required(VERSION 2.8)

project(algorithms)

set(CMAKE_MACOSX_RPATH TRUE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall")

if(coverage)
	set(GCC_COVERAGE_COMPILE_FLAGS "-fprofile-arcs -ftest-coverage")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")	
endif(coverage)

enable_testing()

add_subdirectory(tests)
add_subdirectory(libalgos)
