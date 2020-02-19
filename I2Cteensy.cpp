#include "I2Cteensy.h"

SSD1306::I2Cteensy::I2Cteensy(unsigned char address) {
  this->address = address;
}

SSD1306::I2Cteensy::~I2Cteensy() {}

bool SSD1306::I2Cteensy::init() {
  Wire.begin();
  return true;
}

bool SSD1306::I2Cteensy::send(const unsigned char *data, int size) {
  Wire.beginTransmission(address);
  if (Wire.write((char *)data, size) == size) {
    Wire.endTransmission();
    return true;
  }
  Wire.endTransmission();

  return false;
}