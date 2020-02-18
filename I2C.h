#pragma once

namespace SSD1306 {
    class I2C {
      public:
        virtual ~I2C(){};
        virtual bool init() { return false; };
        virtual bool send(const unsigned char* data, int size) {
            return false;
        };
    };
} // namespace SSD1306