#include "stm32f4xx_hal.h"
#include "led.hpp"

int main (void) {  
  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  Led green_led{GPIOG, GPIO_PIN_13};
  Led red_led{GPIOG, GPIO_PIN_14};

  /* Infinite loop */
  while (1)
  {
    green_led.toggle();
    red_led.toggle();
    HAL_Delay(500);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	}

  return 0;
}


