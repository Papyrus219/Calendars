cmake_minimum_required(VERSION 3.31)
project(Calendar)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SRC src/lib/*cpp)
set(SOURCES ${SRC})
add_library(Calendar STATIC ${SOURCES})
target_include_directories(Calendar PUBLIC SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/src/interface)

if (MSVC)
    target_compile_options(Calendar PRIVATE /W4)
else()
    target_compile_options(Calendar PRIVATE -Wall -Wextra -Wpedantic)
endif()

file(GLOB_RECURSE TEST_SRC src/test/*cpp)
set(TEST_SOURCES ${TEST_SRC})

add_executable(NO ${TEST_SOURCES})
target_link_libraries(NO PRIVATE Calendar)
