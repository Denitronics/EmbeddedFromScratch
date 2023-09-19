set(EXECUTABLE ${PROJECT_NAME}.elf)

add_executable(${EXECUTABLE} 
    main.c
    #syscalls.c
    #sysmem.c
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

target_compile_options(${EXECUTABLE}
  PRIVATE
    -mcpu=cortex-m4
    -mthumb
    -mfpu=fpv4-sp-d16
    -mfloat-abi=hard
    -fdata-sections
    -ffunction-sections
    -Wall
    -specs=nano.specs
    $<$<CONFIG:Debug>:-Og>
)

target_link_options(${EXECUTABLE} PUBLIC
  -T${CMAKE_SOURCE_DIR}/config/LinkerScript/STM32F429ZITX_FLASH.ld
  -mcpu=cortex-m4
  -mthumb
  -mfpu=fpv4-sp-d16
  -mfloat-abi=hard
  -specs=nosys.specs
  -lc
  -lm
  -lnosys
  -Wl,-Map=${PROJECT_NAME}.map,--cref
  -Wl,--gc-sections
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