cmake_minimum_required(VERSION 3.10)
project(robot)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

include_directories(include)

add_executable(robot
    src/main.cpp
    src/robot.cpp
    src/robotair.cpp
)