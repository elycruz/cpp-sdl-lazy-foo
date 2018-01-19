cmake_minimum_required(VERSION 3.9)
project(cpp_sdl_hello_world)
set(CMAKE_CXX_STANDARD 11)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})

add_executable(cpp_sdl_hello_world main.cpp)
target_link_libraries(cpp_sdl_hello_world ${SDL2_LIBRARIES})