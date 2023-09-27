cmake_minimum_required(VERSION 3.26)
project(Cytorch2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Cytorch2 main.cpp
        value.cpp
        value.h
        myFunctions.cpp
        myFunctions.h
        Linear_Layer.cpp
        Linear_Layer.h)
