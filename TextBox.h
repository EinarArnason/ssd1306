#pragma once

/*
    Use fonts with sizes multiple of 8.
*/

namespace SSD1306 {
    class TextBox {
      private:
        int pageStart;
        int pageEnd;
        int columnStart;
        int columnEnd;
        int dataLength;

      public:
        TextBox();
        TextBox(int x, int y, int width, int height);
        TextBox(const TextBox& old);
        int x();
        int y();
        int width();
        int height();
        int size();
    };
} // namespace SSD1306