cmake_minimum_required(VERSION 3.9.1)

project(cpp_lazy_foo_sdl2_5)

set(CMAKE_CXX_STANDARD 17)

include(Env.cmake)

find_package(SDL2 REQUIRED)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS})

add_executable(cpp_lazy_foo_sdl2_5 main.cpp)

target_link_libraries(cpp_lazy_foo_sdl2_5 ${SDL2_LIBRARIES})
