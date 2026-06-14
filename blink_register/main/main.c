#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "soc/gpio_reg.h"
#include "soc/soc.h"

#define LED_PIN 2

void GPIO_Init_Register(void){
    #if LED_PIN < 32
        REG_WRITE(GPIO_ENABLE_W1TS_REG, 1 << LED_PIN);
    #else
        REG_WRITE(GPIO_ENABLE1_W1TS_REG, 1 << (LED_PIN - 32));
    #endif
}

void GPIO_Set_High(void){
    #if LED_PIN < 32
        REG_WRITE(GPIO_OUT_W1TS_REG, 1 << LED_PIN);
    #else
        REG_WRITE(GPIO_OUT1_W1TS_REG, 1 << (LED_PIN - 32));
    #endif
}

void GPIO_Set_Low(void){
    #if LED_PIN < 32
        REG_WRITE(GPIO_OUT_W1TC_REG, 1 << LED_PIN);
    #else
        REG_WRITE(GPIO_OUT1_W1TC_REG, 1 << (LED_PIN - 32));
    #endif
}

void app_main(void)
{
    GPIO_Init_Register();
    while(1){
        GPIO_Set_High();
        vTaskDelay(pdMS_TO_TICKS(1000));
        GPIO_Set_Low();
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
