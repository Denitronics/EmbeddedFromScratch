@ECHO OFF

:: Script for flashing STM32 microcontrollers using STM32CubeProgrammer
STM32_Programmer_CLI --connect port=SWD --write build/src/core/embedded_from_scratch.hex --go