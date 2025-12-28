#include <iostream>
#include "Rules.h"
#include "Board.h"
using namespace std;


void Rules::Play() {
    Board gameboard; //make the actual object
    int i = 0; // keeps track of the color of the object %2 = red otherwise black
    char input;
    int place;
    bool go = true;
    gameboard.Start();   
    while (go) {
        if (i % 2 == 0){ //picks the color of the chip
            chip.setcolor(Disc::red);
        }
        else{
            chip.setcolor(Disc::black);
        }
        cout << (i % 2 == 0 ? "Red" : "Black") << "moves. Select column [1-7], 'q' to quit:" << endl;
        cin >> input;
        if (input == 'q'){ 
            cout << "Game Over" << endl;
            break;
        }
        place = input - '0';
        if ((place > 7) || (place < 1)){ //check for valid column
            cout << "Invalid column entered." << endl;
            continue;
        }
        if (!gameboard.dropDisc(place - 1, chip.getcolor())){
            continue;
        }
        if (gameboard.HorizontalWin(chip.getcolor())){
            gameboard.Start();
            cout << "CONGRATULATIONS!! " << (i % 2 == 0 ? "RED" : "BLACK") << " WINS!!" << endl;
            break;
        }
        if (gameboard.VerticalWin(chip.getcolor())){
            gameboard.Start();
            cout << "CONGRATULATIONS!! " << (i % 2 == 0 ? "RED" : "BLACK") << " WINS!!" << endl;
            break;
        }
        if (gameboard.DiagonalWin(chip.getcolor())){
            gameboard.Start();
            cout << "CONGRATULATIONS!! " << (i % 2 == 0 ? "RED" : "BLACK") << " WINS!!" << endl;
            break;
        }
        gameboard.Start();
        if (gameboard.Checkfull()){
            go = false;
        }
        else{
            ++i;
        }
    }
}

