#include "I2Cpi.h"

SSD1306::I2Cpi::I2Cpi(std::string device, unsigned char address) {
    this->device = device;
    this->address = address;
}

SSD1306::I2Cpi::~I2Cpi() { close(i2c); }

bool SSD1306::I2Cpi::init() {
    i2c = open(device.c_str(), O_RDWR);
    if (i2c < 0) {
        return false;
    }

    if (ioctl(i2c, I2C_SLAVE, address) >= 0) {
        std::cout << "I2C initialized" << std::endl;
        return true;
    }

    return false;
}

bool SSD1306::I2Cpi::send(const unsigned char* data) {
    if (write(i2c, data, sizeof(data)) == sizeof(data)) {
        std::cout << "Sent: 0x" << std::hex << (int)data[0] << std::hex
                  << (int)data[1] << std::endl;
        return true;
    }

    return false;
}