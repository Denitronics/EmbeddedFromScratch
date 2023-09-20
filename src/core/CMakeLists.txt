set(EXECUTABLE ${PROJECT_NAME}.elf)

add_executable(${EXECUTABLE} 
    main.c
    syscalls.c
    sysmem.c
    startup_stm32f429zitx.s
)

target_link_libraries(${EXECUTABLE}
  PUBLIC
    hal
)

target_compile_definitions(${EXECUTABLE}
  PRIVATE
    -DUSE_HAL_DRIVER
    -DSTM32F429xx
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