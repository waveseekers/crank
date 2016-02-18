cmake_minimum_required(VERSION 3.3)

# Definitions
set(PROJECT_NAME_STR crank)
set(PROJECT_LIB_NAME ${PROJECT_NAME_STR}_lib)
set(PROJECT_LIB_NAME_STATIC "${PROJECT_LIB_NAME}_static")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


# Options
option(CRANK_BUILD_SHARED "Build shared library" ON)
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

# Create header and source groups
source_group("Header Files" FILES ${INC_FILES})
source_group("Source Files" FILES ${SRC_FILES})
set(ALL_SOURCE_FILES ${INC_FILES} ${SRC_FILES})


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
# Unit tests
#
# Add the unit tests to the build process
if(CRANK_BUILD_TESTS)
    # Add the unit test project
    add_subdirectory(test/)
endif()


##########################################################################
# Build
#
# Assign the include directories
include_directories(${CRANK_INCLUDES})
include_directories(${Boost_INCLUDE_DIRS})

if(CRANK_BUILD_SHARED)
    add_library(${PROJECT_LIB_NAME} SHARED ${ALL_SOURCE_FILES})
endif()


# add the executable
set(SOURCE_FILES main.cpp)
add_executable(crank ${PROJECT_SOURCE_DIR}/src/${SOURCE_FILES})
target_link_libraries(crank ${PROJECT_LIB_NAME})