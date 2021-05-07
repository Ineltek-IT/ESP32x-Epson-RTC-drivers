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
//#include "i2c_port_config.h"
#include "rx8010sj.h"
#include "conversions.h"



void app_main(void)
{
    time_t now; 
    struct tm set_time_tm;
    struct tm get_time_tm;
    uint8_t *data_rd = (uint8_t *)malloc(1);
    int ret;

    now = 1620139886;

    printf("Now: %ld\n",now);
    localtime_r(&now, &set_time_tm);


    
    ret = rx8010_init();
    rx8010_set_time(&set_time_tm);

    for (int i = 1000; i >= 0; i--) {
        ret = rx8010_read_reg(RX8010_REG_HOUR, data_rd, 1);
        printf("%02x : ", *data_rd);
        ret = rx8010_read_reg(RX8010_REG_MIN, data_rd, 1);
        printf("%02x : ", *data_rd);
        ret = rx8010_read_reg(RX8010_REG_SEC, data_rd, 1);
        printf("%02x\n", *data_rd);

        vTaskDelay(2000 / portTICK_PERIOD_MS);
        rx8010_get_time(&get_time_tm);
        printf("From get time %d\n", get_time_tm.tm_sec);
        
    }
    printf("Restarting now.\n");
    fflush(stdout);
    esp_restart();
}
