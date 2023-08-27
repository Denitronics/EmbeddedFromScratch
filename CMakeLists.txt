cmake_minimum_required(VERSION 3.20)

# Enable ARMCLANG newer policy
#cmake_policy(SET CMP0123 NEW)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/config)

#include(target_link)

project(embedded_from_scratch
    LANGUAGES C CXX ASM
    DESCRIPTION "Tutorial how to use cmake for embedded projects")

add_subdirectory(external)
add_subdirectory(src)