#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <cstring>
#include <iostream>
#include <list>
#ifndef Board_h
#define Board_h
#include "Square.h"
using namespace std;

class Board {

	Square sudoku_board[9][9];

	void printBoard();

public:

	Board();

	int generateBoard(int, int);
	bool isInvalid(int, int);
	bool delete_randomtiles(int);

};
#endif /* Board_h */