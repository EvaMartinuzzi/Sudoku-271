//
//  Board.hpp
//  getsudokuprojectfinal
//
//  Created by Aparna Gollakota on 12/7/16.
//  Copyright © 2016 Aparna Gollakota. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifndef Board_hpp
#define Board_hpp
#include "Square.h"

class Board {
    
    Square sudoku_board[9][9];
    Square starting_board[9][9];
    Square play_board[9][9];
    
    void printBoard();
    void edit();
    
public:
    
    Board();
    
    int coordinates;
    bool isFixedValue[81];
    int values[81];
    int generateBoard(int x, int y);
    bool isInvalid(int x, int y);
    bool makeStartingBoard();
    bool delete_randomtiles(int difficulty);
    bool inputTile(int x, int y, int n);
    
    
};



#endif /* Board_h */
