#include "stm32f4xx_hal.h"
#include "led.hpp"
#include "logger.h"
#include "serial.hpp"

int main (void) {  
  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();
  
  bsp::Led green_led{GPIOG, GPIO_PIN_13};
  bsp::Serial serial{115200};

  /* Infinite loop */
  while (1)
  {
    green_led.toggle();
    HAL_Delay(1000);
    serial.write("Test!\n\r", 8);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	}

  return 0;
}


