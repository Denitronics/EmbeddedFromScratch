#!/bin/sh
# Shell script for building the STM32 based project using CMake and ninja.
# It has to be executed in the main project dir

HW_MODEL=""

buildSw() {
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
cmake -GNinja -DCMAKE_TOOLCHAIN_FILE=../config/CMake/STM32F429/Toolchain.cmake -DCMAKE_BUILD_TYPE=Debug -DHW_MODEL=STM32F429 ../
# Build the project using ninja build system
ninja
# Navigate back to project dir
cd ../
}

# check if the corresponding MCU is supported
while getopts "vh:" flag; do
  case $flag in
    v) 
       HW_MODEL=$2
       echo "HW:$2";;
    h) echo "-v: Choose HW version"
       echo "-h: This information" ;;
    \?) 
      echo "Invalid option! Check available flags with -h"
      exit 1 ;;
  esac
done

if [[ "$HW_MODEL" == "STM32F429" ]]
then
  buildSw
else 
  echo "HW=$HW_MODEL\n\rPlease, select supported HW version"
  exit 1
fi