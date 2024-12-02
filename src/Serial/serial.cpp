#include "serial.hpp"


namespace bsp {

Serial::Serial(uint32_t speed) {
    // GPIO clock enable
    __HAL_RCC_GPIOA_CLK_ENABLE();
    // Initialize GPIO pins
    /**USART1 GPIO Configuration
    PA9     ------> USART1_TX
    PA10     ------> USART1_RX
    */
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = GPIO_PIN_9|GPIO_PIN_10;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART1;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    // UART clock enable
    __HAL_RCC_USART1_CLK_ENABLE();
    // Initialize UART
    huart1.Instance = USART1;
	huart1.Init.BaudRate = speed;
	huart1.Init.WordLength = UART_WORDLENGTH_8B;
	huart1.Init.StopBits = UART_STOPBITS_1;
	huart1.Init.Parity = UART_PARITY_NONE;
	huart1.Init.Mode = UART_MODE_TX_RX;
	huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart1.Init.OverSampling = UART_OVERSAMPLING_16;

    HAL_UART_Init(&huart1);
}

bool Serial::write(char* pData, uint32_t size) {
    bool res{false};

    if (HAL_UART_Transmit(&huart1, reinterpret_cast<uint8_t*>(pData), size, timeout) == HAL_OK) {
        res = true;
    }

    return res;
}

bool Serial::read(char* pData, uint32_t size) {
    bool res{false};

    if (HAL_UART_Receive(&huart1, reinterpret_cast<uint8_t*>(pData), size, timeout) == HAL_OK) {
        res = true;
    }

    return res;
}

} // namespace bsp