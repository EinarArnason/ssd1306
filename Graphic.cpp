#include "Graphic.h"

SSD1306::Graphic::Graphic() {
    buffer = nullptr;
    width = 0;
    height = 0;
    size = 0;
}

SSD1306::Graphic::Graphic(unsigned char* buffer, int width, int height) {
    this->buffer = buffer;
    this->width = width;
    this->height = height;
    this->size = (width * height) / 8;
}

SSD1306::Graphic::Graphic(const Graphic& old) {
    buffer = old.buffer;
    width = old.width;
    height = old.height;
    size = old.size;
}

int SSD1306::Graphic::getWidth() { return width; }

int SSD1306::Graphic::getHeight() { return height; }

int SSD1306::Graphic::getSize() { return size; }

unsigned char* SSD1306::Graphic::getData() { return buffer; }
