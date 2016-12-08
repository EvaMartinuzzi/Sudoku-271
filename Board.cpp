#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <cstring>
#include <iostream>
#include <list>
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
	bool Board::user_interface();
};

bool Board::delete_randomtiles(int difficulty)
{
	int nDelete;
	int rx, ry;

	if (difficulty == 1) {
		nDelete = 10;
		sudoku_board[0][3].setCurrentValue(0);
		sudoku_board[3][7].setCurrentValue(0);
		sudoku_board[0][0].setCurrentValue(0);
		sudoku_board[5][5].setCurrentValue(0);
		sudoku_board[1][6].setCurrentValue(0);
		sudoku_board[2][5].setCurrentValue(0);
		sudoku_board[1][2].setCurrentValue(0);
		sudoku_board[2][4].setCurrentValue(0);
		sudoku_board[1][8].setCurrentValue(0);
		sudoku_board[8][8].setCurrentValue(0);

	}
	else if (difficulty == 2) {
		nDelete = 20;
		sudoku_board[0][3].setCurrentValue(0);
		sudoku_board[3][7].setCurrentValue(0);
		sudoku_board[0][0].setCurrentValue(0);
		sudoku_board[5][5].setCurrentValue(0);
		sudoku_board[1][6].setCurrentValue(0);
		sudoku_board[2][5].setCurrentValue(0);
		sudoku_board[1][2].setCurrentValue(0);
		sudoku_board[2][4].setCurrentValue(0);
		sudoku_board[1][8].setCurrentValue(0);
		sudoku_board[8][8].setCurrentValue(0);
		sudoku_board[4][6].setCurrentValue(0);
		sudoku_board[6][3].setCurrentValue(0);
		sudoku_board[8][1].setCurrentValue(0);
		sudoku_board[3][6].setCurrentValue(0);
		sudoku_board[6][4].setCurrentValue(0);
		sudoku_board[7][3].setCurrentValue(0);
		sudoku_board[2][4].setCurrentValue(0);
		sudoku_board[1][8].setCurrentValue(0);
		sudoku_board[8][8].setCurrentValue(0);
		sudoku_board[4][6].setCurrentValue(0);
	}
	else if (difficulty == 3) {
		nDelete = 30;
		sudoku_board[0][3].setCurrentValue(0);
		sudoku_board[3][7].setCurrentValue(0);
		sudoku_board[0][0].setCurrentValue(0);
		sudoku_board[5][5].setCurrentValue(0);
		sudoku_board[1][6].setCurrentValue(0);
		sudoku_board[2][5].setCurrentValue(0);
		sudoku_board[1][2].setCurrentValue(0);
		sudoku_board[2][4].setCurrentValue(0);
		sudoku_board[1][8].setCurrentValue(0);
		sudoku_board[8][8].setCurrentValue(0);
		sudoku_board[4][6].setCurrentValue(0);
		sudoku_board[6][3].setCurrentValue(0);
		sudoku_board[8][1].setCurrentValue(0);
		sudoku_board[3][6].setCurrentValue(0);
		sudoku_board[1][7].setCurrentValue(0);
		sudoku_board[2][7].setCurrentValue(0);
		sudoku_board[3][8].setCurrentValue(0);
		sudoku_board[4][4].setCurrentValue(0);
		sudoku_board[5][2].setCurrentValue(0);
		sudoku_board[6][4].setCurrentValue(0);
		sudoku_board[7][3].setCurrentValue(0);
		sudoku_board[2][4].setCurrentValue(0);
		sudoku_board[1][8].setCurrentValue(0);
		sudoku_board[8][8].setCurrentValue(0);
		sudoku_board[4][6].setCurrentValue(0);
		sudoku_board[6][3].setCurrentValue(0);
		sudoku_board[8][1].setCurrentValue(0);
		sudoku_board[3][6].setCurrentValue(0);
	}
	/*for (int i = 0; i < nDelete; i++) {
		srand(time(NULL));
		rx = rand()%9;
		srand(time(NULL));
		ry = rand()%9;
		sudoku_board[rx][ry].getCurrentValue();
		sudoku_board[rx][ry].setCurrentValue(0);
	*/
	printBoard();
	return true;
}

bool Board::user_interface(){
	int x, y, n, q;
	while (user_interface){}
	cout << "Type '1' to input a value or '2' to quit!" << endl;
	cin >> q;
	if(q == '1'){
		cout << "Enter the row you would like to enter your value in" << endl;
		cin >> x;
		cout << "Enter the column you would like to enter a value in" << endl;
		cin >> y;
		cout << "Enter a value" << endl;
		cin >> n;

		sudoku_board[x][y].setCurrentValue(n);
		printBoard();
		return true;
	}
	else if (q == '2'){
		return false;
	}

}

bool Board::check_solved(){

}



bool Board::isInvalid(int current_x, int current_y){

	// verify the row is still valid

	for (int x = 0; x < 9; x++){
		bool check_one = (x != current_x);
		bool check_two = (sudoku_board[current_y][x].getCurrentValue() == sudoku_board[current_y][current_x].getCurrentValue());

		if (check_one){
			if (check_two){
				return true;
			}
		}
	}

	// verify the column is still valid

	for (int y = 0; y < 9; y++){
		bool check_one = (y != current_y);
		bool check_two = (sudoku_board[y][current_x].getCurrentValue() == sudoku_board[current_y][current_x].getCurrentValue());

		if (check_one){
			if (check_two){
				return true;
			}
		}
	}

	// verify the box its in is still valid

	int current_box_x = current_x / 3;
	int current_box_y = current_y / 3;

	for (int x = 3 * current_box_x; x < (3 * current_box_x + 3); x++){
		for (int y = 3 * current_box_y; y < (3 * current_box_y + 3); y++){
			bool check_one = (x != current_x) && (y != current_y);
			bool check_two = (sudoku_board[y][x].getCurrentValue() == sudoku_board[current_y][current_x].getCurrentValue());

			if (check_one){
				if (check_two){
					return true;
				}
			}
		}
	}

	return false;

}

int Board::generateBoard(int previous_x, int previous_y){

	int current_x, current_y;

	// shifts to the "next" position on the Board
	// gets ready to solve that recursively...
	if (previous_x == 8 && previous_y == 8){
		return 0;
	}
	else if (previous_x == 8){
		current_x = 0;
		current_y = previous_y + 1;
	}
	else{
		current_x = previous_x + 1;
		current_y = previous_y;
	}

	printBoard();

	Square& current_square = sudoku_board[current_y][current_x];

	int attempt_value = current_square.getAvailableValue();
	current_square.setCurrentValue(attempt_value);

	while (attempt_value != -1){

		if (!Board::isInvalid(current_x, current_y)){
			if (generateBoard(current_x, current_y) == 0){
				return 0;
			}
		}

		attempt_value = current_square.getAvailableValue();
		current_square.setCurrentValue(attempt_value);

	};

	current_square.reset();
	return -1;

}

void Board::printBoard(){
	printf("\n");
	for (int x = 0; x < 9; x++){
		for (int y = 0; y < 9; y++){
			printf("%i ", sudoku_board[y][x].getCurrentValue());
		}
		printf("\n");
	}
}

Board::Board(){

	generateBoard(-1, 0);
	printBoard();

}