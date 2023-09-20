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