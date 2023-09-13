#!/bin/sh

# Script for build the project using CMake and ninja
cd build
cmake -GNinja -DCMAKE_TOOLCHAIN_FILE=../config/CMake/Toolchain.cmake -DCMAKE_BUILD_TYPE=Debug ../
ninja
cd ../