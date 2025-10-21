cmake_minimum_required(VERSION 4.1.0)

project(raylib01)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_BUILD_TYPE Debug)

include_directories(lib/raylib-5.5/include
    include/)

link_directories(lib/raylib-5.5/lib)

add_executable(${PROJECT_NAME} WIN32 main.cpp
    src/maps.cpp
)

#add_definitions(-mwindows)

target_link_libraries(${PROJECT_NAME} raylib winmm)

# cmake .. -G "MinGW Makefiles" -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++
