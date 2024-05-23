CMAKE_MINIMUM_REQUIRED(VERSION 3.7 FATAL_ERROR)

PROJECT(Parser_LALR_Expression VERSION 1.0)

SET(CMAKE_CXX_STANDARD 17)

SET(EXECUTABLE_NAME lalr-expression)

configure_file(config.hpp.in config.hpp)

find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

# BISON_TARGET(expression_parser expression_parser.y ${CMAKE_CURRENT_BINARY_DIR}/expression_parser.tab.cpp)
# FLEX_TARGET(expression_lexer expression_lexer.l ${CMAKE_CURRENT_BINARY_DIR}/expression_lexer.yy.cpp)
# ADD_FLEX_BISON_DEPENDENCY(expression_lexer expression_parser)

BISON_TARGET(parser parser.yy ${CMAKE_CURRENT_BINARY_DIR}/parser.cc)
FLEX_TARGET(scanner scanner.ll ${CMAKE_CURRENT_BINARY_DIR}/scanner.cc)
ADD_FLEX_BISON_DEPENDENCY(scanner parser)

# add_executable(${EXECUTABLE_NAME} main.cpp ${FLEX_expression_lexer_OUTPUTS} ${BISON_expression_parser_OUTPUTS})
add_executable(${EXECUTABLE_NAME} main.cpp driver.cc ${FLEX_scanner_OUTPUTS} ${BISON_parser_OUTPUTS})
target_include_directories(${EXECUTABLE_NAME} PUBLIC "${PROJECT_BINARY_DIR}")
target_include_directories(${EXECUTABLE_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
