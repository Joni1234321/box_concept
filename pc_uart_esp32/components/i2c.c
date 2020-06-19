#include "i2c.h"

// https://gist.github.com/mws-rmain/2ba434cd2a3f32d6d343c1c60fbd65c8


#define FREQ				100000           /*!< I2C master clock frequency */
#define PORT_NUM			I2C_NUM_1        /*!< I2C port number for master dev */
#define TX_BUF  			0                /*!< I2C master do not need buffer */
#define RX_BUF  			0                /*!< I2C master do not need buffer */

#define WRITE_BIT                          I2C_MASTER_WRITE /*!< I2C master write */
#define READ_BIT                           I2C_MASTER_READ  /*!< I2C master read */
#define ACK_CHECK_EN                       0x1              /*!< I2C master will check ack from slave*/
#define ACK_CHECK_DIS                      0x0              /*!< I2C master will not check ack from slave */
#define ACK_VAL                            0x0              /*!< I2C ack value */
#define NACK_VAL                           0x1              /*!< I2C nack value */


i2c_port_t i2c_port = I2C_NUM_0;
i2c_cmd_handle_t cmd;

esp_err_t i2c_init(uint8_t sda, uint8_t scl)
{
    int i2c_master_port = PORT_NUM;
    i2c_config_t conf;

    // Set as master
    conf.mode = I2C_MODE_MASTER;

    // Pins
    conf.sda_io_num = sda;
    conf.scl_io_num = scl;

    // Pullup enabled
    conf.sda_pullup_en = GPIO_PULLUP_ENABLE;
    conf.scl_pullup_en = GPIO_PULLUP_ENABLE;

    // Frequency
    conf.master.clk_speed = FREQ;

    // Set config
    i2c_param_config(i2c_master_port, &conf);

    // Init
    return i2c_driver_install(i2c_master_port, conf.mode, RX_BUF, TX_BUF, 0);
}


esp_err_t i2c_write(uint32_t address, uint8_t *data, size_t size)
{
	// Init sequence
	i2c_cmd_handle_t i2c_commands = i2c_cmd_link_create();

	// Create Command Sequence
	i2c_master_start(i2c_commands);
	i2c_master_write_byte(i2c_commands, (address << 1) | WRITE_BIT, ACK_CHECK_EN);	// Address
	i2c_master_write(i2c_commands, data, size, ACK_CHECK_EN);						// Write bytes
	i2c_master_stop(i2c_commands);

	// Execute command
	esp_err_t ret = i2c_master_cmd_begin(i2c_port, i2c_commands, 1000 / portTICK_RATE_MS);

	// Restore memory
	i2c_cmd_link_delete(i2c_commands);
	return ret;
}

esp_err_t i2c_read(uint32_t address, uint8_t *data, size_t size)
{
	// No data to read
	if (size == 0) {
		return ESP_OK;
	}

	// Init sequence
	i2c_cmd_handle_t cmd = i2c_cmd_link_create();

	// Create command sequence
	i2c_master_start(cmd);
	i2c_master_write_byte(cmd, (address << 1) | READ_BIT, ACK_CHECK_EN);	// Address
	if (size > 1) {
		i2c_master_read(cmd, data, size - 1, ACK_VAL);					// Read bytes except last byte
	}
	i2c_master_read_byte(cmd, data + size - 1, NACK_VAL);				// Read last byte
	i2c_master_stop(cmd);

	// Execute command
	esp_err_t ret = i2c_master_cmd_begin(i2c_port, cmd, 1000 / portTICK_RATE_MS);

	// Restore memory
	i2c_cmd_link_delete(cmd);
	return ret;
}
