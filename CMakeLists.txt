cmake_minimum_required(VERSION 3.31)
project(Calendars VERSION 0.8.0 LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(CALENDAR_BUILD_TESTS "Build Calendar tests" OFF)

set(SOURCES
    src/lib/calendar.cpp
    src/lib/event.cpp
    src/lib/gregorian/gregorian_calendar.cpp
    src/lib/gregorian/gregorian_month.cpp
    src/lib/hebrew/hebrew_calendar.cpp
    src/lib/hebrew/hebrew_month.cpp
)


add_library(${PROJECT_NAME} STATIC ${SOURCES})
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/include>
    $<INSTALL_INTERFACE:include>
)

if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif()

if(CALENDAR_BUILD_TESTS)
    include(FetchContent)

    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
    )
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    enable_testing()

    set(TEST_SOURCES src/test/main.cpp)

    add_executable(calendar_tests ${TEST_SOURCES})
    target_link_libraries(calendar_tests PRIVATE Calendars gtest_main)

    include(GoogleTest)
    gtest_discover_tests(calendar_tests)

endif()



