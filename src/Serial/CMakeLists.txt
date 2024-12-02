# Serial library name
set(LIBRARY_NAME serial)

set(SERIAL_INC_PATH ${PROJECT_SOURCE_DIR}/include/Serial)

add_library(${LIBRARY_NAME}
  serial.cpp
)

target_link_libraries(${LIBRARY_NAME}
  PUBLIC
    hal
)

target_include_directories(${LIBRARY_NAME}
  PUBLIC
    ${SERIAL_INC_PATH}
)