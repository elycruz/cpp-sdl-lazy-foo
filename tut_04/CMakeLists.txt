cmake_minimum_required(VERSION 3.9)
project(cpp_lazy_foo_sdl2_4)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})

add_executable(cpp_lazy_foo_sdl2_4 main.cpp)

target_link_libraries(cpp_lazy_foo_sdl2_4 ${SDL2_LIBRARIES})
