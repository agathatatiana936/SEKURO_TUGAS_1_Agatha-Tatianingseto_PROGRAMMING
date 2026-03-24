cmake_minimum_required(VERSION 3.10)
project(soal_2_cmake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# output
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# header
include_directories(include)

add_executable(soal_2_cmake
    src/main.cpp
    src/mcu.cpp
    src/mcu_cam_controller.cpp
    src/mcu_walker.cpp
)