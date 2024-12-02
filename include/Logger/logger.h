#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <stdint.h>

#ifdef __cplusplus
extern "C"{
#endif 

typedef enum
{
    LOG_LEVEL_ERROR,
    LOG_LEVEL_INFORMATION,
    LOG_LEVEL_DEBUG
} LogLevel;

void log_error(char const * const format, ...);
void log_info(char const * const format, ...);
void log_debug(char const * const format, ...);
void log_debug_array(char const * const label, void const *array, uint16_t const len);

#ifdef __cplusplus
}
#endif

#endif // LOGGER_HPP