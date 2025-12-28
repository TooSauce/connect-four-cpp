#include <iostream>
#include "Board.h"
using namespace std;

Board::Board(){
    table = new Disc*[row]; //table made up of empty disc cells
    for (int i = 0; i < row; ++i){
        table[i] = new Disc[col];
        for (int j = 0; j < col; ++ j){
            table[i][j].setcolor(Disc::empty);
        }
    }
    xvalue = -1; //so win condition doesn't end game
    yvalue = -1;
}
Board::~Board(){
    for (int i = 0; i < row; ++i){
        delete[] table[i];
    }
    delete[] table;
}

bool Board::HorizontalWin(Disc::Color color){
    int count = 0; //sequence tracker
    if (yvalue < 0) {
        return false;
    }
    else{
        for (int i = 0; i < col; ++i){
            if (table[yvalue][i].getcolor() == color){
                ++count;
                if (count >= 4){
                    return true;
                }
            }
            else {
                count = 0;
            }
        }
        return false;
    }
}

bool Board::VerticalWin(Disc::Color color){
    int count = 0;
    if (xvalue < 0) {
        return false;
    }
    else{
        for (int i = 0; i < row; ++i){
            if (table[i][xvalue].getcolor() == color){
                ++count;
                if (count >= 4){
                    return true;
                }
            }
            else {
                count = 0;
            }
        }
        return false;
    }
}

bool Board::DiagonalWin(Disc::Color color){
    if ((xvalue < 0) || (yvalue < 0)){
        return false;
    }
    int count = 1; //starts at 1 because of the disc you placed
    int x = xvalue;
    int y = yvalue;
    int y2 = y + 1; //moves to the next col
    int x2 = x + 1; //moves to the next row
    while (true){ //checks bottom left to top right
        if ((y2 >= row) || (x2 >= col)){
            break;
        }
        if(table[y2][x2].getcolor() != color){
            break;
        }
        ++count; //keeps the tracker moving
        ++x2;
        ++y2;
    }
    y2 = y - 1; //checks top right to bottom left
    x2 = x - 1; //exact opposite of above
    while(true){
        if ((y2 < 0) || (x2 < 0)){
            break;
        }
        if (table[y2][x2].getcolor() != color){
            break;
        }
        ++count;
        --y2;
        --x2;
    }
    if (count >= 4){
        return true;
    }
    count = 1;  //checks bottom right to top left
    y2 = y - 1; //checks previous col
    x2 = x + 1; //checks next row
    while (true) {
        if ((y2 < 0) || (x2 >= col)){ 
            break;  
        }
        if (table[y2][x2].getcolor() != color) {
            break;
        }
        ++count;
        --y2;
        ++x2;
    }
    y2 = y + 1; //checks top left to bottom right
    x2 = x - 1;
    while(true){
        if ((y2 >= row) || (x2 < 0)){
            break;
        }
        if (table[y2][x2].getcolor() != color){
            break;
        }
        ++count;
        ++y2;
        --x2;
    }
    if (count >= 4){
        return true;
    }
    return false;
}

bool Board::Checkfull(){ // returns false there is an empty space
    for (int i = 0; i < row; ++i){
        for (int j = 0; j < col; ++j){
            if (table[i][j].getcolor() == Disc::empty){
                return false;
            }
        }
    }
    cout << "The board is full. The game is a draw." << endl;
    return true;
}
void Board::Start() {
    cout << "| [1]     [2]     [3]     [4]     [5]     [6]     [7] |" << endl;
    cout << "| - - - - - - - - - - - - - - - - - - - - - - - - - - |" << endl;
    for (int i = 0; i < row; ++i){
        for (int j = 0; j < col; ++j){
             cout << "| (" << table[i][j].getsymbol() << ") | ";
        }
        cout << endl;
    }
    cout << "| - - - - - - - - - - - - - - - - - - - - - - - - - - |" << endl;
}

bool Board::dropDisc(int column, Disc::Color color){
    if (column < 0 || column >= col){
        cout << "Invalid column entered." << endl;
        return false;
    }
    for (int i = row - 1; i >= 0; --i){
        if (table[i][column].getcolor() == Disc::empty){
            table[i][column].setcolor(color);
            yvalue = i;
            xvalue = column;
            return true;
        }
    }
    cout << "Sorry that column is full. Try again." << endl;
    return false;
}