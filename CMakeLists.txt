set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-deprecated-register")

cmake_minimum_required(VERSION 3.1)

project(something VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(EXECUTABLE_NAME my_wc)
configure_file(config.hpp.in config.hpp)

# find_package(BISON REQUIRED)
# find_package(FLEX REQUIRED)

# BISON_TARGET(mc_parser
#              simple_wc_mc_parser.yy
#              ${CMAKE_CURRENT_BINARY_DIR}/mc_parser.tab.cc)
# FLEX_TARGET(mc_lexer
#             simple_wc_mc_lexer.l
#             ${CMAKE_CURRENT_BINARY_DIR}/mc_lexer.yy.cc)
# ADD_FLEX_BISON_DEPENDENCY(mc_lexer mc_parser)
# BISON_TARGET(expression_parser
#             expression_parser.y
#             ${CMAKE_CURRENT_BINARY_DIR}/expression_parser.cpp)
# FLEX_TARGET(expression_lexer
#             expression_lexer.l
#             ${CMAKE_CURRENT_BINARY_DIR}/expression_lexer.cpp)

# add_executable(${EXECUTABLE_NAME}
#     main.cpp
#     expression_driver.cpp
#
#     # ${FLEX_mc_lexer_OUTPUTS}
#     # ${BISON_mc_parser_OUTPUTS}
#     ${FLEX_expression_lexer_OUTPUTS}
#     ${BISON_expression_parser_OUTPUTS}
# )
# target_include_directories(${EXECUTABLE_NAME}
#     PRIVATE
#         ${CMAKE_CURRENT_SOURCE_DIR}
#         #${FLEX_INCLUDE_DIRS}
#         ${CMAKE_CURRENT_BINARY_DIR})
add_library(nodes OBJECT nodes.cpp)
add_executable(foo foo.cpp)
target_link_libraries(foo nodes)
