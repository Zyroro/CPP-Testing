cmake_minimum_required(VERSION 3.20)

project(CPPTesting)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES
    CONFIGURE_DEPENDS
    "*.cpp"
    "*.h"
    "*.hpp"
)

add_executable(CPPTesting ${SOURCES})