cmake_minimum_required(VERSION 3.14)
set ( DCMAKE_TOOLCHAIN_FILE "~/vcpkg/scripts/buildsystems/vcpkg.cmake")
set (GTest_DIR "/home/dreamy/vcpkg/installed/x64-linux/share/gtest")
project(aoi LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest CONFIG REQUIRED)
find_package(Boost COMPONENTS REQUIRED)
include_directories(${BOOST_INCLUDE_DIRS})




enable_testing()
add_subdirectory(test)
add_subdirectory(src)

