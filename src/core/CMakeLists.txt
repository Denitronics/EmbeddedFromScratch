set(EXECUTABLE ${PROJECT_NAME}.elf)

set(STARTUP_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/${HW_MODEL}/startup.s
    ${CMAKE_CURRENT_SOURCE_DIR}/${HW_MODEL}/stm32_it.c)

add_executable(${EXECUTABLE} 
    main.c
    ${STARTUP_FILES} 
)

target_link_libraries(${EXECUTABLE}
  PUBLIC
    hal
)

target_compile_definitions(${EXECUTABLE}
  PRIVATE
    -DUSE_HAL_DRIVER
    -D${HW_MODEL}xx
)

# Print executable size
add_custom_command(TARGET ${EXECUTABLE}
        POST_BUILD
        COMMAND arm-none-eabi-size ${EXECUTABLE})

# Create hex file
add_custom_command(TARGET ${EXECUTABLE}
        POST_BUILD
        COMMAND arm-none-eabi-objcopy -O ihex ${EXECUTABLE} ${PROJECT_NAME}.hex
        COMMAND arm-none-eabi-objcopy -O binary ${EXECUTABLE} ${PROJECT_NAME}.bin)