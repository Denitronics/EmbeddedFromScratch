# How to name the library
set(LIBRARY_NAME hal)

# Path to HAL configuration files
set(HAL_CONFIG_PATH ${PROJECT_SOURCE_DIR}/config/HAL)

# Path to HAL sources
set(HAL_SOURCES 
    src/stm32f4xx_hal_cortex.c
    src/stm32f4xx_hal_dma_ex.c
    src/stm32f4xx_hal_dma.c
    src/stm32f4xx_hal_exti.c
    src/stm32f4xx_hal_flash_ex.c
    src/stm32f4xx_hal_flash_ramfunc.c
    src/stm32f4xx_hal_flash.c
    src/stm32f4xx_hal_gpio.c
    src/stm32f4xx_hal_pwr_ex.c
    src/stm32f4xx_hal_pwr.c
    src/stm32f4xx_hal_rcc_ex.c
    src/stm32f4xx_hal_rcc.c
    src/stm32f4xx_hal.c
    ${HAL_CONFIG_PATH}/system_stm32f4xx.c
    ${HAL_CONFIG_PATH}/stm32f4xx_it.c
    ${HAL_CONFIG_PATH}/stm32f4xx_hal_msp.c
  )

add_library(${LIBRARY_NAME}
  ${HAL_SOURCES}
)

target_include_directories(${LIBRARY_NAME}
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include/CMSIS
)

target_compile_options(${LIBRARY_NAME}
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

target_link_options(${LIBRARY_NAME} PUBLIC
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