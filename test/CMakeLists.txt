cmake_minimum_required(VERSION 3.14)
project(aoi LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(../src)

add_executable(aoi main.cpp)

target_link_libraries(aoi PUBLIC GTest::gmock GTest::gtest GTest::gtest_main GTest::gmock_main aoi_lib ${Boost_LIBRARIES})
add_test( aoi aoi )