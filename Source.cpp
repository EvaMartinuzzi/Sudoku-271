#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <cstring>
#include <iostream>
#include <list>

using namespace std;

class Square {

	list<int> available_values;

	int current_value;

public:

	Square();

	void reset();

	int getAvailableValue();

	int getCurrentValue();
	void setCurrentValue(int new_value);

};

int Square::getAvailableValue(){

	if (available_values.empty()){
		return -1;
	}

	int return_val = available_values.front();
	available_values.pop_front();

	return return_val;

}

int Square::getCurrentValue(){
	return current_value;
}

void Square::setCurrentValue(int new_value){
	current_value = new_value;
}

void Square::reset(){
	setCurrentValue(-1);

	// intializing the available values list
	for (int x = 0; x < 9; x++){
		available_values.push_front(x + 1);
	}

	for (int x = 0; x < 1000; x++){
		int rand_one = rand() % 3;
		if (rand_one < (rand() % 6)){
			available_values.push_front(available_values.back());
			available_values.pop_back();
		}
		else{
			available_values.push_back(available_values.front());
			available_values.pop_front();
		}
	}

}

Square::Square(void){

	reset();

}

class Board {

	Square sudoku_board[9][9];

	void printBoard();

public:

	Board();

	int generateBoard(int, int);
	bool isInvalid(int, int);

};

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

void displayRules(){
	cout << "\n\n\t\t\tHOW TO PLAY\n" << endl;
	cout << "\n\nSudoku is a game with a grid of 81 squares, divided into \n nine blocks with nine squares each." << endl;
	cout << "\n\nEach of the nine squares must contain numbers 1 - 9" << endl;
	cout << "\n\nEach number may only appear once in a column, row, or square." << endl;
	cout << "\n\nGood luck!" << endl;
	cout << "Enter any key to continue\n" << endl;
}

void loadMenu(){

	int selection;
	Board sudoku_board();

	cout << "Select Your Option (enter number):\n" << endl;
	cout << "\t1. Start\n" << endl;
	cout << "\t2. Rules\n" << endl;

	cin >> selection;

	switch (selection) {
	case 1:
		cout << "hello world" << endl;
		break;
	case 2:
		displayRules();
		loadMenu();
		break;
	default:
		cout << ("Stop that. Press '1' or '2'. There is no third option. Please stop.") << endl;
		break;
	}
}

int main(int argv, char **argc){

	srand(time(NULL));
	Board sudoku;
	system("pause");
	return 0;

}