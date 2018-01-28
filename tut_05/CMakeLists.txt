cmake_minimum_required(VERSION 3.10)

project(cpp_lazy_foo_sdl2_4)

set(CMAKE_CXX_STANDARD 17)

include(Env.cmake)

find_package(SDL REQUIRED)
find_package(SDL_image REQUIRED)

INCLUDE_DIRECTORIES(${SDL_INCLUDE_DIR} ${SDL_IMAGE_DIRS})

add_executable(cpp_lazy_foo_sdl2_5 main.cpp)

target_link_libraries(cpp_lazy_foo_sdl2_5 ${SDL_LIBRARY} ${SDL_IMAGE_LIBRARIES})
