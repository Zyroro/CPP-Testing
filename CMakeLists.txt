cmake_minimum_required(VERSION 3.20)

project(CPPTesting)

file(GLOB_RECURSE PROJECT_FILES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp"
)

add_custom_target(CPPTesting SOURCES ${PROJECT_FILES})