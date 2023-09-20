# How to name the library
set(LIBRARY_NAME hal)

# Path to HAL configuration files
set(HAL_CONFIG_PATH ${PROJECT_SOURCE_DIR}/config/HAL)
set(HAL_SRC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/STM32Cube_FW_F4_V1.27.0/Drivers/STM32F4xx_HAL_Driver/Src)
set(HAL_INC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/STM32Cube_FW_F4_V1.27.0/Drivers/STM32F4xx_HAL_Driver/Inc)

# Path to HAL sources
set(HAL_SOURCES 
    ${HAL_SRC_PATH}/stm32f4xx_hal_cortex.c
    ${HAL_SRC_PATH}/stm32f4xx_hal_dma_ex.c
    ${HAL_SRC_PATH}/stm32f4xx_hal_dma.c
    ${HAL_SRC_PATH}/stm32f4xx_hal_exti.c
    ${HAL_SRC_PATH}/stm32f4xx_hal_flash_ex.c
    ${HAL_SRC_PATH}/stm32f4xx_hal_flash_ramfunc.c
    ${HAL_SRC_PATH}/stm32f4xx_hal_flash.c
    ${HAL_SRC_PATH}/stm32f4xx_hal_gpio.c
    ${HAL_SRC_PATH}/stm32f4xx_hal_pwr_ex.c
    ${HAL_SRC_PATH}/stm32f4xx_hal_pwr.c
    ${HAL_SRC_PATH}/stm32f4xx_hal_rcc_ex.c
    ${HAL_SRC_PATH}/stm32f4xx_hal_rcc.c
    ${HAL_SRC_PATH}/stm32f4xx_hal.c
    ${HAL_CONFIG_PATH}/system_stm32f4xx.c
    ${HAL_CONFIG_PATH}/stm32f4xx_it.c
    ${HAL_CONFIG_PATH}/stm32f4xx_hal_msp.c
  )

add_library(${LIBRARY_NAME}
  ${HAL_SOURCES}
)

target_include_directories(${LIBRARY_NAME}
  PUBLIC
    ${HAL_INC_PATH}
    ${HAL_CONFIG_PATH}
    ${CMAKE_CURRENT_SOURCE_DIR}/include/CMSIS
)