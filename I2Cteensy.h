#pragma once

#include "I2C.h"
#include <Arduino.h>
#include <i2c_t3.h>

namespace SSD1306 {
class I2Cteensy : public I2C {
private:
  unsigned char address;

public:
  I2Cteensy(unsigned char address);
  ~I2Cteensy();
  // Returns true if initialization is successful
  bool init();
  bool send(const unsigned char *data, int size);
};
} // namespace SSD1306