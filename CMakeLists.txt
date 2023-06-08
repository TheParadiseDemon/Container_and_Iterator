cmake_minimum_required(VERSION 3.21)
project(Container_and_Iterator)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Container_and_Iterator
        "Container and Iterator.cpp"
        Container.cpp
        Container.h
        Iterator.h)
