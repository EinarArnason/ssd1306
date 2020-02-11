#pragma once

/*
    Use fonts with sizes multiple of 8.
*/

class TextBox {
  private:
    int pageStart;
    int pageEnd;
    int columnStart;
    int columnEnd;

  public:
    TextBox();
    TextBox(int pageStart, int pageEnd, int columnStart, int columnEnd);
    int x();
    int y();
    int width();
    int height();
};