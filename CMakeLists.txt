CMAKE_MINIMUM_REQUIRED(VERSION 3.7 FATAL_ERROR)

PROJECT(Parser_LALR_Expression VERSION 1.0)

SET(CMAKE_CXX_STANDARD 17)

SET(EXECUTABLE_NAME lalr-expression)

configure_file(config.hpp.in config.hpp)

add_executable(${EXECUTABLE_NAME} main.cpp)
target_include_directories(${EXECUTABLE_NAME} PUBLIC "${PROJECT_BINARY_DIR}")
