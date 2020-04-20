#include "TextBox.h"

SSD1306::TextBox::TextBox() {
    pageStart = 0;
    pageEnd = 0;
    columnStart = 0;
    columnEnd = 0;
    dataLength = 0;
}

SSD1306::TextBox::TextBox(int x, int y, int width, int height) {
    this->pageStart = x;
    this->pageEnd = y;
    this->columnStart = width;
    this->columnEnd = height;
    this->dataLength = width * height / 8;
}

int SSD1306::TextBox::x() { return pageStart; }
int SSD1306::TextBox::y() { return pageEnd; }
int SSD1306::TextBox::width() { return columnStart; }
int SSD1306::TextBox::height() { return columnEnd; }
int SSD1306::TextBox::size() { return dataLength; }