#pragma once

namespace SSD1306 {
    class I2C {
      public:
        virtual ~I2C(){};
        virtual bool init() = 0;
        virtual bool send(const unsigned char* data) = 0;
    };
} // namespace SSD1306