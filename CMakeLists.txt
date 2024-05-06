cmake_minimum_required(VERSION 3.10)  # Minimum version of CMake required

# Set the project name and specify the C++ standard
project(ScannerProject LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    ${PROJECT_SOURCE_DIR}/antlr4-runtime/
    ${PROJECT_SOURCE_DIR}/generated/
)
file(GLOB antlr4-cpp-src
    ${PROJECT_SOURCE_DIR}/antlr4-runtime/*.cpp
    ${PROJECT_SOURCE_DIR}/antlr4-runtime/atn/*.cpp
    ${PROJECT_SOURCE_DIR}/antlr4-runtime/dfa/*.cpp
    ${PROJECT_SOURCE_DIR}/antlr4-runtime/misc/*.cpp
    ${PROJECT_SOURCE_DIR}/antlr4-runtime/support/*.cpp
    ${PROJECT_SOURCE_DIR}/antlr4-runtime/tree/*.cpp
    ${PROJECT_SOURCE_DIR}/antlr4-runtime/tree/pattern/*.cpp
    ${PROJECT_SOURCE_DIR}/antlr4-runtime/tree/xpath/*.cpp
)

add_library(antlr4-runtime ${antlr4-cpp-src})

# Add executable target with source files
add_executable(parser
    generated/SysyBaseListener.cpp 
    generated/SysyBaseVisitor.cpp 
    generated/SysyLexer.cpp 
    generated/SysyParser.cpp 
    generated/SysyListener.cpp 
    generated/SysyVisitor.cpp 
    src/ast.cpp 
    src/AstVisitor.cpp
    src/main.cpp
)

# Link the required libraries
target_link_libraries(parser
    antlr4-runtime
)
