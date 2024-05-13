#ifndef LED_HPP

#include "stm32f4xx_hal.h"


class Led {

public:
    /**
     * @brief Class constructor
     * @param GPIOx - port of the GPIO pin
     * @param GPIO_Pin - GPIO pin number
     */
    Led(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

    /// @brief Deleted default constructor
    Led() = delete;

    /// @brief Toggle the LED
    void toggle() const;

    /// @brief Turn the LED on
    void turnOn() const;

    /// @brief Turn the LED off
    void turnOff() const;

private:
    // Pointer to a gpio port
    GPIO_TypeDef* gpioPort{nullptr};

    // GPIO pin number
    uint16_t gpioPin{0};
};

#endif // LED_HPP