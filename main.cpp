#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <cstring>
#include <iostream>
#include <list>
#include "Board.h"
#include "Square.h"

using namespace std;

void displayRules();
void loadMenu();

int main(int argv, char **argc){

	srand(time(NULL));
	Board sudoku;
	system("pause");

	sudoku.delete_randomtiles(3);

	system("pause");
	return 0;

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

