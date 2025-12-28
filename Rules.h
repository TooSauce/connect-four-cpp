#pragma once
#include "Board.h"
#include "Disc.h"
#include <iostream>

class Rules{
private:
    Board gameboard;
    Disc chip;
public:
    void Play();
};