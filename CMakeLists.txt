# Version CMake
cmake_minimum_required(VERSION 3.10)

# Project name
project(get_version_from_git)

## Set new version in package.xml ##
execute_process(
    COMMAND git describe --exact-match --tags
                OUTPUT_VARIABLE GIT_TAG
                ERROR_QUIET)

execute_process(
    COMMAND git rev-parse --abbrev-ref HEAD
            OUTPUT_VARIABLE GIT_BRANCH
            ERROR_QUIET)

string(STRIP "${GIT_TAG}" GIT_TAG)
string(STRIP "${GIT_BRANCH}" GIT_BRANCH)

if ("release" STREQUAL "${GIT_BRANCH}")
    file(READ ${PROJECT_SOURCE_DIR}/package.xml PACKAGE)

    string(FIND "${PACKAGE}" "<version>" BEGIN_VERSION)
    string(FIND "${PACKAGE}" "</version>" END_VERSION)

    math(EXPR BEGIN_VERSION "${BEGIN_VERSION}+9")
    math(EXPR LENGTH "${END_VERSION}-${BEGIN_VERSION}")

    string(SUBSTRING "${PACKAGE}" ${BEGIN_VERSION} ${LENGTH} OLD_VERSION)

    if ("" STREQUAL "${GIT_TAG}")
        message(FATAL_ERROR "Release branch cannot be without a tag")
    else()
        set(NEW_VERSION ${GIT_TAG})
        string(REPLACE "${OLD_VERSION}" ${NEW_VERSION} PACKAGE ${PACKAGE})
        file(WRITE ${PROJECT_SOURCE_DIR}/package.xml ${PACKAGE})
        message(STATUS "Package version " ${NEW_VERSION})
    endif()
endif()

# Source files
set(SOURCES
    source/main.cpp
)

# Compiling target
add_executable(${PROJECT_NAME} ${SOURCES})