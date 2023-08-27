set(PROJECT_NAME EMBEDDED_FROM_SCRATCH)

add_executable(${PROJECT_NAME} 
    main.cpp
    stm32h7xx_it.c
    startup_stm32h7b3lihxq.s
)

target_link(${PROJECT_NAME}
  ${PROJ_PATH}/config/STM32H7B3LIHXQ_FLASH
)