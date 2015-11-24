cmake_minimum_required (VERSION 3.0)
project (application)

add_subdirectory(src)

set (CMAKE_CXX_STANDARD 11)

add_executable(application application.cpp)

add_library(test_extension1 SHARED test_extension1.cpp)
add_library(test_extension2 SHARED test_extension2.cpp)

target_link_libraries(application src)
target_link_libraries(test_extension1 src)
target_link_libraries(test_extension2 src)
