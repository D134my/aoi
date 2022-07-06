cmake_minimum_required(VERSION 3.14)
project(aoi LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES
    ./*.h
    ./*.cpp
)

add_library(aoi_lib STATIC ${SOURCES})