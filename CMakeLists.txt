cmake_minimum_required(VERSION 3.10)

# Project name
project(planets CXX C)

add_subdirectory(libraries/glfw)
add_subdirectory(libraries/glm)
include_directories(src/dependencies)

# Directories
set(SRC_DIR src)
set(BIN_DIR bin)

file(MAKE_DIRECTORY ${BIN_DIR})

IF(MSVC)
    message("Manually configure flags when using MSVC")
ELSEIF(LINUX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wpedantic -g")
ENDIF()

# Compiler flags
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/${BIN_DIR})

add_subdirectory(src)
