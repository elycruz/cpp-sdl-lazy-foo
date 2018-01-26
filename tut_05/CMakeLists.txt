cmake_minimum_required(VERSION 3.9)
project(cpp_lazy_foo_sdl2_4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake-modules/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})

add_executable(cpp_lazy_foo_sdl2_5 main.cpp)

target_link_libraries(cpp_lazy_foo_sdl2_5 ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})
