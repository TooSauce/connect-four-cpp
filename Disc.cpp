#include <iostream>
#include "Disc.h"
using namespace std;

Disc::Disc(){
    color = empty;
}
Disc::Disc(Color c){
    color = c;
}
void Disc::setcolor(Color c){
    color = c;
}
Disc::Color Disc::getcolor() const{
    return color;
}
char Disc::getsymbol() const{
    if (color == empty){
        return ' ';
    }
    else if (color == red){
        return 'R';
    }
    else if (color == black){
        return 'B';
    }
    else{
        return '?';
    }
}