cmake_minimum_required (VERSION 3.0)
project (extensible)

set (CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(application application.cpp)

add_library(test_extension1 SHARED test_extension1.cpp)
add_library(test_extension2 SHARED test_extension2.cpp)

add_library(extensible SHARED
        src/manager.cpp
        src/shared_object.cpp
        src/version.cpp
        include/szabi/extensible/extensible_export.h
        include/szabi/extensible/extension.h
        include/szabi/extensible/iextension.h
        include/szabi/extensible/manager.h
        include/szabi/extensible/server.h
        include/szabi/extensible/shared_object.h
        include/szabi/extensible/version.h
        include/szabi/extensible.h)

include(GenerateExportHeader)
generate_export_header(extensible
        EXPORT_MACRO_NAME EXTENSIBLE
        EXPORT_FILE_NAME ${PROJECT_SOURCE_DIR}/include/szabi/extensible/extensible_export.h)

if(UNIX)
    target_link_libraries(application extensible dl)
else()
    target_link_libraries(application extensible)
endif(UNIX)

target_link_libraries(test_extension1 extensible)
target_link_libraries(test_extension2 extensible)

install(TARGETS extensible DESTINATION lib)
install(FILES
        include/szabi/extensible/extensible_export.h
        include/szabi/extensible/extension.h
        include/szabi/extensible/iextension.h
        include/szabi/extensible/manager.h
        include/szabi/extensible/server.h
        include/szabi/extensible/shared_object.h
        include/szabi/extensible/version.h
        DESTINATION include/szabi/extensible)
install(FILES include/szabi/extensible.h DESTINATION include/szabi)