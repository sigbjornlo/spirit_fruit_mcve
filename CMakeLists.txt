cmake_minimum_required(VERSION 3.7)
project(SpiritFruit)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp fruit.cpp fruit.h)
add_executable(SpiritFruit ${SOURCE_FILES})