cmake_minimum_required(VERSION 3.7)
project(SpiritFruit)

set(CMAKE_CXX_STANDARD 14)
# add_definitions(-DBOOST_SPIRIT_X3_DEBUG)

# set(SOURCE_FILES fruit.cpp main.cpp) # This works
set(SOURCE_FILES main.cpp fruit.cpp)   # This doesn't

add_executable(SpiritFruit ${SOURCE_FILES})