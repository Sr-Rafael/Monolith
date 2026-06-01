cmake_minimum_required(VERSION 3.31)

project(Monolith)

add_library(
    Monolith STATIC
    src/Monolith.hpp
    src/display/display.cpp)

target_link_libraries(Monolith SDL2)
