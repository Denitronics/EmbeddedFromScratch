@ECHO OFF

:: Under reconstruction!!!
:: Shell script for building the STM32 based project using CMake and ninja.
:: It has to be executed in the main project dir

:: Check if the build folder don't exist and create one
if exist build\ (
  echo Build directory already exists
) else (
  echo Create new build directory
  mkdir build
)

:: Navigate to build folder
cd build
:: Execute CMake
cmake -GNinja -DCMAKE_TOOLCHAIN_FILE=../config/CMake/Toolchain.cmake -DCMAKE_BUILD_TYPE=Debug ../
:: Build the project using ninja build system
ninja
:: Navigate back to project dir
cd ../