# LOGGER library name
set(LIBRARY_NAME logger)

set(LOGGER_INC_PATH ${PROJECT_SOURCE_DIR}/include/Logger)

add_library(${LIBRARY_NAME}
  logger.c
)

target_compile_definitions(${LIBRARY_NAME}
    PUBLIC
    SYSTEM_LOG_LEVEL=1
)

target_link_libraries(${LIBRARY_NAME}
  PUBLIC
    hal
)

target_include_directories(${LIBRARY_NAME}
  PUBLIC
    ${LOGGER_INC_PATH}
)