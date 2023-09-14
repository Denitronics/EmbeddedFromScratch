#!/bin/sh
# Shell script for building the STM32 based project using CMake and ninja.
# It has to be executed in the main project dir

# Check if the build folder don't exist and create one
if [ ! -d "build" ] 
then
  echo "Creating build folder!"
  mkdir build
else
  echo "Build folder already exist"
fi
# Navigate to build folder
cd build
# Execute CMake
cmake -GNinja -DCMAKE_TOOLCHAIN_FILE=../config/CMake/Toolchain.cmake -DCMAKE_BUILD_TYPE=Debug ../
# Build the project using ninja build system
ninja
# Navigate back to project dir
cd ../