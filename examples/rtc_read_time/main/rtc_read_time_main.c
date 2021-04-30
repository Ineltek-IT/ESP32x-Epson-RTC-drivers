/* Hello World Example
 
   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h> 
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "driver/i2c.h"
#include "i2c_port_config.h"
#include "rx8010sj.h"


void app_main(void)
{
    printf("Hello world!\n");
     int ret;
     uint8_t *data_rd = (uint8_t *)malloc(1);

    ret = rx8010_init();


    for (int i = 1000; i >= 0; i--) {
        ret = rx8010_read_reg(RX8010_REG_HOUR, data_rd, 1);
        printf("%02x : ", *data_rd);
        ret = rx8010_read_reg(RX8010_REG_MIN, data_rd, 1);
        printf("%02x : ", *data_rd);
        ret = rx8010_read_reg(RX8010_REG_SEC, data_rd, 1);
        printf("%02x\n", *data_rd);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    printf("Restarting now.\n");
    fflush(stdout);
    esp_restart();
}