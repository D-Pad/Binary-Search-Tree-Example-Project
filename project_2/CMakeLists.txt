cmake_minimum_required(VERSION 3.10)
project(Assignments VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
	main
	src/BinarySearchTree.cpp
	src/CSVparser.cpp
	src/Course.cpp
	src/main.cpp
)

target_include_directories(main PRIVATE src)

