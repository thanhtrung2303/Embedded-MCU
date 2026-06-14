#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <stdint.h>
#include "driver/gpio.h"

#define GPIO_BASE_REG 0x60004000
#define IO_MUX_BASE_REG 0x60009000

#define GPIO_OUT_W1TS_REG (*(volatile uint32_t *)(GPIO_BASE_REG + 0x0008))
#define GPIO_OUT_W1TC_REG (*(volatile uint32_t *)(GPIO_BASE_REG + 0x000C))
#define GPIO_ENABLE_W1TS_REG (*(volatile uint32_t *)(GPIO_BASE_REG + 0x0024))
#define GPIO_ENABLE_W1TC_REG (*(volatile uint32_t *)(GPIO_BASE_REG + 0x0028))
#define GPIO_IN_REG (*(volatile uint32_t *)(GPIO_BASE_REG + 0x003C))

#define IO_MUX_GPIO4_REG (*(volatile uint32_t *)(IO_MUX_BASE_REG + 0x0014))
#define IO_MUX_GPIO5_REG (*(volatile uint32_t *)(IO_MUX_BASE_REG + 0x0018))
#define GPIO_PIN5_REG (*(volatile uint32_t *)(GPIO_BASE_REG + 0x0088))


#define LED_PIN 4
#define BUTTON_PIN 5

void IRAM_ATTR gpio_isr_handler(void *arg)
{
    if((GPIO_IN_REG & (1 << BUTTON_PIN)) == 0){
        GPIO_OUT_W1TS_REG = (1 << LED_PIN);
    }
    else{
        GPIO_OUT_W1TC_REG = (1 << LED_PIN);
    }
}

void app_main(void)
{
    IO_MUX_GPIO4_REG |= (1 << 12);
    IO_MUX_GPIO5_REG |= (1 << 12);
    IO_MUX_GPIO5_REG |= (1 << 9);
    IO_MUX_GPIO5_REG |= (1 << 8);
    GPIO_ENABLE_W1TS_REG = (1 << LED_PIN);
    GPIO_ENABLE_W1TC_REG = (1 << BUTTON_PIN);  
    GPIO_PIN5_REG &= ~(7 << 7);
    GPIO_PIN5_REG |= (3 << 7);
    gpio_install_isr_service(0);
    gpio_isr_handler_add(BUTTON_PIN, gpio_isr_handler, NULL);
}