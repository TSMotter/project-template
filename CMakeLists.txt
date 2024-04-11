cmake_minimum_required(VERSION 3.13)
project(project_template)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Variable TARGET_GROUP should be passed as an argument when calling cmake
set(TARGET_GROUP app CACHE STRING "Specify the TARGET_GROUP?")

add_subdirectory(lib)
add_subdirectory(external)
add_subdirectory("${TARGET_GROUP}")
