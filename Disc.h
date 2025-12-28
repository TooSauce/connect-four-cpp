#pragma once
#include <iostream>

class Disc {
public:
    enum Color{empty, red, black};
private:
    Color color;
public:
    Disc();
    Disc(Color c);
    void setcolor(Color c);
    Color getcolor() const;
    char getsymbol() const;

};