#pragma once

#include "I2C.h"
#include <fcntl.h>
#include <iostream>
#include <linux/i2c-dev.h>
#include <string>
#include <sys/ioctl.h>
#include <unistd.h>

namespace SSD1306 {
    class I2Cpi : public I2C {
      private:
        int i2c;
        std::string device;
        unsigned char address;

      public:
        I2Cpi(const char* device, unsigned char address);
        ~I2Cpi();
        // Returns true if initialization is successful
        bool init();
        bool send(const unsigned char* data);
    };
} // namespace SSD1306