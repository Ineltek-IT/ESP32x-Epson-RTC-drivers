
#define I2C_MASTER_SDA_IO 5         // select GPIO specific to your project
#define I2C_MASTER_SCL_IO 4

#define I2C_MASTER_PORT_NUM 0
#define RTC_ADDR 0x32

#define ACK_CHECK_EN 0x1                        /*!< I2C master will check ack from slave*/
#define ACK_CHECK_DIS 0x0                       /*!< I2C master will not check ack from slave */
#define ACK_VAL 0x0                             /*!< I2C ack value */
#define NACK_VAL 0x1                            /*!< I2C nack value */

#define RX8010_REG_SEC		0x10
#define RX8010_REG_MIN		0x11
#define RX8010_REG_HOUR		0x12
#define RX8010_REG_WDAY		0x13
#define RX8010_REG_MDAY		0x14
#define RX8010_REG_MONTH	0x15
#define RX8010_REG_YEAR		0x16
