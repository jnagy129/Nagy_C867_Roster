cmake_minimum_required(VERSION 3.15)
project(test_c867)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(test_c867
        degree.h
        networkStudent.cpp
        networkStudent.h
        roster.cpp
        roster.h
        securityStudent.cpp
        securityStudent.h
        softwareStudent.cpp
        softwareStudent.h
        student.cpp
        student.h)
