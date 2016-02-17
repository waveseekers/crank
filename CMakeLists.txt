cmake_minimum_required(VERSION 3.3)

# Definitions
set(PROJECT_NAME_STR crank)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


# Options
option(CRANK_BUILD_TESTS "Build tests" OFF)


# Project title and define versioning
project(${PROJECT_NAME_STR} C CXX)
set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 1)
set(PROJECT_VERSION_PATCH 0)


# Include paths
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/modules/")
set(CRANK_INCLUDES ${CRANK_INCLUDES} ${PROJECT_SOURCE_DIR}/src)
set(CRANK_INCLUDES ${CRANK_INCLUDES} ${PROJECT_SOURCE_DIR}/shared)
set(CRANK_INCLUDES ${CRANK_INCLUDES} ${PROJECT_SOURCE_DIR}/vendor)


# Gather the header and source files
file(GLOB_RECURSE INC_FILES ${PROJECT_SOURCE_DIR}/src/shared/*.hpp)
file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/src/shared/*.cpp)


##########################################################################
# Find "Boost" => "boost"
# => Boost_INCLUDE_DIRS		: include directories for Boost
# => Boost_LIBRARIES	    : Boost libraries
# => Boost_LIBRARY_DIRS	    : Boost libray directories
find_package(Boost COMPONENTS system date_time thread REQUIRED)

if(NOT Boost_INCLUDE_DIR)
    message(FATAL_ERROR "Boost headers required to build project")
endif()


##########################################################################
# Find "Cassandra" => "cassandra"
# => CASSANDRA_INCLUDE_DIR		: include directory for Cassandra.h
# => CASSANDRA_LIBRARIES	    : Cassandra libraries
find_package(Cassandra)

if(NOT Cassandra_INCLUDE_DIR)
    message(FATAL_ERROR "Cassandra headers required to build project")
endif()


##########################################################################
# Build
#
# Assign the include directories
include_directories(${CRANK_INCLUDES})


# add the executable
set(SOURCE_FILES main.cpp)
add_executable(crank ${PROJECT_SOURCE_DIR}/src/${SOURCE_FILES})