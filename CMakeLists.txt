cmake_minimum_required (VERSION 3.0)
project (extensible)

set (CMAKE_CXX_STANDARD 11)

include_directories(include
        ${CMAKE_CURRENT_BINARY_DIR})

add_executable(application application.cpp)

add_library(test_extension1 SHARED test_extension1.cpp)
add_library(test_extension2 SHARED test_extension2.cpp)

add_library(extensible SHARED
        src/manager.cpp
        src/shared_object.cpp
        src/version.cpp)

include(GenerateExportHeader)
generate_export_header(extensible
        EXPORT_MACRO_NAME EXTENSIBLE
        EXPORT_FILE_NAME ${PROJECT_SOURCE_DIR}/include/extensible_export.h)

if(unix)
    target_link_libraries(application extensible dl)
else()
    target_link_libraries(application extensible dl)
endif(unix)
target_link_libraries(test_extension1 extensible)
target_link_libraries(test_extension2 extensible)
