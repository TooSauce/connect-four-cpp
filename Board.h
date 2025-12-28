#pragma once
#include "Disc.h"
#include <iostream>
#include <string>

class Board {
private:
    static const int row = 6;
    static const int col = 7;
    Disc** table;
    int xvalue; //keeps track of column the disc is dropped
    int yvalue; //keeps track of row the disc is dropped

public:
    Board();
    ~Board();
    void Start();
    bool dropDisc(int column, Disc::Color color);
    bool Checkfull();
    bool HorizontalWin(Disc::Color color);
    bool VerticalWin(Disc::Color color);
    bool DiagonalWin(Disc::Color color);
};