#include "TextBox.h"

TextBox::TextBox() {
    pageStart = 0;
    pageEnd = 0;
    columnStart = 0;
    columnEnd = 0;
}

TextBox::TextBox(int x, int y, int width, int height) {
    this->pageStart = x;
    this->pageEnd = y;
    this->columnStart = width;
    this->columnEnd = height;
}

int TextBox::x() { return pageStart; }
int TextBox::y() { return pageEnd; }
int TextBox::width() { return columnStart; }
int TextBox::height() { return columnEnd; }