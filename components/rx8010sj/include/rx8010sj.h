#ifndef RX8010SJ_H
#define RX8010SJ_H


#include <stdio.h>
#include <sdkconfig.h>

#define RX8010SJ_PORT 0 //CONFIG_RX8010SJ_PORT
#define RX8010SJ_SCL 4 //CONFIG_RX8010SJ_SCL
#define RX8010SJ_SDA 5 //CONFIG_RX8010SJ_SDA
#define I2C_MASTER_FREQ_HZ 400000
#define RTC_ADDR 0x32

// RX-8010 Register definitions
#define RX8010_REG_SEC		0x10
#define RX8010_REG_MIN		0x11
#define RX8010_REG_HOUR		0x12
#define RX8010_REG_WDAY		0x13
#define RX8010_REG_MDAY		0x14
#define RX8010_REG_MONTH	0x15
#define RX8010_REG_YEAR		0x16
// 0x17 is reserved
#define RX8010_REG_ALMIN	0x18
#define RX8010_REG_ALHOUR	0x19
#define RX8010_REG_ALWDAY	0x1A
#define RX8010_REG_TCOUNT0	0x1B
#define RX8010_REG_TCOUNT1	0x1C
#define RX8010_REG_EXT		0x1D
#define RX8010_REG_FLAG		0x1E
#define RX8010_REG_CTRL		0x1F
#define RX8010_REG_USER0	0x20
#define RX8010_REG_USER1	0x21
#define RX8010_REG_USER2	0x22
#define RX8010_REG_USER3	0x23
#define RX8010_REG_USER4	0x24
#define RX8010_REG_USER5	0x25
#define RX8010_REG_USER6	0x26
#define RX8010_REG_USER7	0x27
#define RX8010_REG_USER8	0x28
#define RX8010_REG_USER9	0x29
#define RX8010_REG_USERA	0x2A
#define RX8010_REG_USERB	0x2B
#define RX8010_REG_USERC	0x2C
#define RX8010_REG_USERD	0x2D
#define RX8010_REG_USERE	0x2E
#define RX8010_REG_USERF	0x2F
// 0x30 is reserved
// 0x31 is reserved
#define RX8010_REG_IRQ		0x32


 esp_err_t rx8010_init(void);
 esp_err_t rx8010_read_reg(uint8_t, uint8_t* , size_t );


#endif //RX8010SJ_H
