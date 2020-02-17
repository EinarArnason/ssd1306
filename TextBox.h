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

      public:
        TextBox();
        TextBox(int x, int y, int width, int height);
        int x();
        int y();
        int width();
        int height();
    };
} // namespace SSD1306