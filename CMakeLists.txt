cmake_minimum_required(VERSION 4.0)
project(School_Management_System)

set(CMAKE_CXX_STANDARD 23)

include_directories(${PROJECT_SOURCE_DIR})

add_executable(School_Management_System
        main.cpp
        Student.cpp
        SchoolManagementSystem.cpp
)
