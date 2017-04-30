cmake_minimum_required(VERSION 3.7)
project(SpiritFruit)

set(CMAKE_CXX_STANDARD 14)
include_directories(${CMAKE_SOURCE_DIR}/lib/spirit/include)

add_definitions(-DBOOST_SPIRIT_X3_DEBUG)

# This works
set(SOURCE_FILES fruit.cpp main.cpp)

# This doesn't (on BOOST 1.64), but will throw an assertion error when built against develop
# set(SOURCE_FILES main.cpp fruit.cpp)

add_executable(SpiritFruit ${SOURCE_FILES})