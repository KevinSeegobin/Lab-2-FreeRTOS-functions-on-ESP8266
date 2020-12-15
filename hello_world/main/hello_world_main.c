#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "driver/gpio.h"
#include "esp_spi_flash.h"
#include "esp_log.h"
#include "esp_system.h"

#define GPIO_OUTPUT_IO_0    2
#define GPIO_OUTPUT_PIN_SEL  (1ULL<<GPIO_OUTPUT_IO_0)

//static const char *TAGM = "main";
//static const char *TASK3 = "Task 3";

void Task1(void *arg)
{
    TickType_t temp = pdMS_TO_TICKS(500);
    uint32_t gpio_num = (uint32_t) arg;
    for(;;)
    {
        //printf("Task1 started\n");      //internal led is active low
        gpio_set_level(gpio_num, 1);
        TickType_t current = xTaskGetTickCount();
        while(xTaskGetTickCount() <= current + temp){continue;}
        vTaskDelay(1000/portTICK_RATE_MS);
    }
}

void Task2(void *arg)
{
    TickType_t temp = pdMS_TO_TICKS(500);
    uint32_t gpio_num = (uint32_t) arg;
    for(;;)
    {
        //printf("Task2 started\n");
        gpio_set_level(gpio_num, 0);
        TickType_t current = xTaskGetTickCount();
        while(xTaskGetTickCount() <= current + temp){continue;}
        vTaskDelay(1000/portTICK_RATE_MS);
    }
    
}

void Task3(void *arg)
{
    uint32_t gpio_num = (uint32_t) arg;
    
    for(;;)
    {
        printf("task3 started\n");
    
        if(gpio_get_level(gpio_num))
        {
            printf("LED on\n");
        }else
        {
            printf("LED off\n");
        }
        vTaskDelay(1000/portTICK_RATE_MS);
    }
}

void app_main()
{
    //TaskHandle_t *task1;
    //TaskHandle_t *task2;
    //TaskHandle_t *task3;

    gpio_config_t io_conf;
    io_conf.intr_type = GPIO_INTR_DISABLE;
    //set as output mode
    io_conf.mode = GPIO_MODE_OUTPUT;
    //bit mask of the pins that you want to set,e.g.GPIO15/16
    io_conf.pin_bit_mask = GPIO_OUTPUT_PIN_SEL;
    //disable pull-down mode
    io_conf.pull_down_en = 0;
    //disable pull-up mode
    io_conf.pull_up_en = 0;
    //configure GPIO with the given settings
    gpio_config(&io_conf);

    xTaskCreate(Task1, "LED on", 1000, (void *)GPIO_OUTPUT_IO_0, 10, NULL);
    xTaskCreate(Task2, "LED off", 1000, (void *)GPIO_OUTPUT_IO_0, 10, NULL);
    xTaskCreate(Task3, "LED notify", 1000, (void *)GPIO_OUTPUT_IO_0, 10, NULL);

    //int cnt = 0;

    while (1) {
        //ESP_LOGI(TAG, "cnt: %d\n", cnt++);
        //vTaskDelay(1000 / portTICK_RATE_MS);
        //gpio_set_level(GPIO_OUTPUT_IO_0, cnt % 2);
        //gpio_set_level(GPIO_OUTPUT_IO_1, cnt % 2);
        //printf("IDLE");
        continue;
    }
}
