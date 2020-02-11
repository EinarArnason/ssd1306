#pragma once

namespace SSD1306 {
    class Graphic {
      private:
        unsigned char* buffer;
        int width;
        int height;
        int size;

      public:
        Graphic();
        Graphic(unsigned char* buffer, int width, int height);
        Graphic(const Graphic& old);
        int getWidth();
        int getHeight();
        int getSize();
        unsigned char* getData();
    };
} // namespace SSD1306