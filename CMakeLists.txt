cmake_minimum_required(VERSION 3.20)

project(rad VERSION 0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-std=c++23 -O3 -g -pg --pedantic -Wall -Wextra")

set(CMAKE_PREFIX_PATH "/usr/local/")

find_package(GTest REQUIRED)
find_package(benchmark REQUIRED)
find_library(ctda NAMES ctda)

include_directories(include src)

add_library(${PROJECT_NAME} 
    STATIC   
        ${PROJECT_SOURCE_DIR}/include/rad.hpp
)

target_include_directories(${PROJECT_NAME} 
    PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/src>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

set_target_properties(${PROJECT_NAME} 
    PROPERTIES 
        LINKER_LANGUAGE CXX)


add_subdirectory(tests)