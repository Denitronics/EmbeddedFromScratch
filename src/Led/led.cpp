#include <cassert>
#include <led.hpp>

namespace bsp {
  Led::Led(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin): gpioPort{GPIOx}, gpioPin{GPIO_Pin} {
    assert(GPIOx != nullptr);
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /* GPIO Ports Clock Enable */
    __HAL_RCC_GPIOG_CLK_ENABLE();

    /*Configure GPIO pin Output Level */
    HAL_GPIO_WritePin(gpioPort, gpioPin, GPIO_PIN_RESET);

    /*Configure GPIO pins : PG13 PG14 */
    GPIO_InitStruct.Pin = gpioPin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(gpioPort, &GPIO_InitStruct);    
  }

  void Led::toggle() const {
      HAL_GPIO_TogglePin(gpioPort, gpioPin);
  }

  void Led::turnOn() const {
      HAL_GPIO_WritePin(gpioPort, gpioPin, GPIO_PIN_SET);
  }

  void Led::turnOff() const {
      HAL_GPIO_WritePin(gpioPort, gpioPin, GPIO_PIN_RESET);
  }
}
