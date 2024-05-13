# LED library name
set(LIBRARY_NAME led)

set(LED_INC_PATH ${PROJECT_SOURCE_DIR}/include/Led)

add_library(${LIBRARY_NAME}
  led.cpp
)

target_link_libraries(${LIBRARY_NAME}
  PUBLIC
    hal 
)

target_include_directories(${LIBRARY_NAME}
  PUBLIC
    ${LED_INC_PATH}
)