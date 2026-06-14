#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <stdint.h>
#include <string.h>
#include "driver/uart.h"

#define GPIO_ENABLE_W1TS_REG (*(volatile uint32_t *)(0x60004024))
#define GPIO_OUT_W1TS_REG (*(volatile uint32_t *)(0x60004008))
#define GPIO_OUT_W1TC_REG (*(volatile uint32_t *)(0x6000400C))
#define IO_MUX_GPIO4_REG (*(volatile uint32_t *)(0x60009014))
#define LED_PIN 4
#define TX_PIN 17
#define RX_PIN 18
void LED_Init_Register(void){
    GPIO_ENABLE_W1TS_REG = (1 << LED_PIN);
    GPIO_OUT_W1TC_REG = (1 << LED_PIN); 
}

void uart_init_driver(void){
    uart_config_t uart_config = {
    .baud_rate = 115200,
    .data_bits = UART_DATA_8_BITS,
    .parity = UART_PARITY_DISABLE,
    .stop_bits = UART_STOP_BITS_1,
    .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
    .source_clk = UART_SCLK_DEFAULT,
    };
    ESP_ERROR_CHECK(uart_param_config(UART_NUM_1, &uart_config));
    ESP_ERROR_CHECK(uart_set_pin(UART_NUM_1, TX_PIN, RX_PIN, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE));
    ESP_ERROR_CHECK(uart_driver_install(UART_NUM_1, 256, 0, 0, NULL, 0));
}

void uart_rx_handler(void *pvParameters){
    uint8_t data[128];
    char buffer[64];
    int buffer_idx= 0;
    while(1){
        int len = uart_read_bytes(UART_NUM_1, data, 1, portMAX_DELAY);
        if(len > 0){
            char ch = (char) data[0];
            uart_write_bytes(UART_NUM_1, &ch, 1);
            if(ch == '\r' || ch == '\n'){
                if(buffer_idx > 0){
                    buffer[buffer_idx] = '\0';
                    if(strcmp(buffer, "LED ON") == 0){
                        GPIO_OUT_W1TS_REG = (1 << LED_PIN);
                        uart_write_bytes(UART_NUM_1, "\r\nDen da bat!\r\n", 15);
                    }
                    else if(strcmp(buffer, "LED OFF") == 0){
                        GPIO_OUT_W1TC_REG = (1 << LED_PIN);
                        uart_write_bytes(UART_NUM_1, "\r\nDen da tat!\r\n", 15);
                    }
                }
                buffer_idx = 0;
                memset(buffer, 0, sizeof(buffer));
            }
            else{
                if(buffer_idx < sizeof(buffer) - 1){
                    buffer[buffer_idx++] = ch;
                }
            }
        }
    }
    vTaskDelete(NULL);
}
void app_main(void)
{
  LED_Init_Register();
    uart_init_driver();
    xTaskCreate(uart_rx_handler, "uart_rx_handler", 4096, NULL, 10, NULL);
}