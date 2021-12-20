# Version CMake
cmake_minimum_required(VERSION 3.10)

# Project name
project(get_version_from_git)

# Add a custom command that produces version.cpp, plus
# a dummy output that's not actually produced, in order
# to force version.cmake to always be re-run before the build
ADD_CUSTOM_COMMAND(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/version.cpp
           ${CMAKE_CURRENT_BINARY_DIR}/_version.cpp
    COMMAND ${CMAKE_COMMAND} -P
            ${CMAKE_CURRENT_SOURCE_DIR}/version.cmake
)

# Source files
set(SOURCES
    source/main.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/version.cpp
)

# Compiling target
add_executable(${PROJECT_NAME} ${SOURCES})
