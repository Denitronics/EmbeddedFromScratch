cmake_minimum_required(VERSION 3.20)

project(embedded_from_scratch)

enable_language(C CXX ASM)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 23)

add_subdirectory(modules)
add_subdirectory(src)