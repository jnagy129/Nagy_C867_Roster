cmake_minimum_required(VERSION 3.15)
project(C867)

set(CMAKE_CXX_STANDARD 14)

add_executable(C867 roster.cpp degree.h student.h student.cpp networkStudent.h securityStudent.h securityStudent.cpp roster.h softwareStudent.cpp softwareStudent.h networkStudent.cpp)