//
//  Board.cpp
//  getsudokuprojectfinal
//
//  Created by Aparna Gollakota on 12/7/16.
//  Copyright © 2016 Aparna Gollakota. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Board.h"
#include "Square.h"
#include <iostream>

using namespace std;

bool Board::makeStartingBoard()
{
	for (int i = 0; i<9; i++) {
		for (int j = 0; j<9; j++) {
			starting_board[i][j].setCurrentValue(sudoku_board[i][j].getCurrentValue());
			play_board[i][j].setCurrentValue(sudoku_board[i][j].getCurrentValue());
		}

	}
	return true;
}

bool Board::inputTile(int x, int y, int n)
{
	if (x>0 && x<10 && y>0 && y<10 && n>0 && n<10)
	{
		if (starting_board[x][y].getCurrentValue() != 0) {
			return false;
		}
		else {
			play_board[x][y].setCurrentValue(n);
			return true;
		}
	}
	else {
		return false;
	}

}

bool Board::delete_randomtiles(int difficulty)
{
	int nDelete;
	int rx, ry;

	if (difficulty == 1) {
		nDelete = 10;
	}
	else if (difficulty == 2) {
		nDelete = 20;
	}
	else if (difficulty == 3) {
		nDelete = 30;
	}
	for (int i = 0; i < nDelete; i++) {
		srand(time(NULL));
		rx = rand() % 81 + 1;
		srand(time(NULL));
		ry = rand() % 81 + 1;
		starting_board[rx][ry].setCurrentValue(0);
		play_board[rx][ry].setCurrentValue(0);
	}
	printBoard();
	return true;
}
bool Board::isInvalid(int current_x, int current_y) {

	// verify the row is still valid

	for (int x = 0; x < 9; x++) {
		bool check_one = (x != current_x);
		bool check_two = (sudoku_board[current_y][x].getCurrentValue() == sudoku_board[current_y][current_x].getCurrentValue());

		if (check_one) {
			if (check_two) {
				return true;
			}
		}
	}

	// verify the column is still valid

	for (int y = 0; y < 9; y++) {
		bool check_one = (y != current_y);
		bool check_two = (sudoku_board[y][current_x].getCurrentValue() == sudoku_board[current_y][current_x].getCurrentValue());

		if (check_one) {
			if (check_two) {
				return true;
			}
		}
	}

	// verify the box its in is still valid

	int current_box_x = current_x / 3;
	int current_box_y = current_y / 3;

	for (int x = 3 * current_box_x; x < (3 * current_box_x + 3); x++) {
		for (int y = 3 * current_box_y; y < (3 * current_box_y + 3); y++) {
			bool check_one = (x != current_x) && (y != current_y);
			bool check_two = (sudoku_board[y][x].getCurrentValue() == sudoku_board[current_y][current_x].getCurrentValue());

			if (check_one) {
				if (check_two) {
					return true;
				}
			}
		}
	}

	return false;

}

int Board::generateBoard(int previous_x, int previous_y) {

	int current_x, current_y;

	// shifts to the "next" position on the Board
	// gets ready to solve that recursively...
	if (previous_x == 8 && previous_y == 8) {
		return 0;
	}
	else if (previous_x == 8) {
		current_x = 0;
		current_y = previous_y + 1;
	}
	else {
		current_x = previous_x + 1;
		current_y = previous_y;
	}

	printBoard();

	Square& current_square = sudoku_board[current_y][current_x];

	int attempt_value = current_square.getAvailableValue();
	current_square.setCurrentValue(attempt_value);

	while (attempt_value != -1) {

		if (!Board::isInvalid(current_x, current_y)) {
			if (generateBoard(current_x, current_y) == 0) {
				return 0;
			}
		}

		attempt_value = current_square.getAvailableValue();
		current_square.setCurrentValue(attempt_value);

	};

	current_square.reset();
	return -1;

}

void Board::printBoard() {
	printf("\n");
	for (int x = 0; x < 9; x++) {
		for (int y = 0; y < 9; y++) {
			printf("%i ", sudoku_board[x][y].getCurrentValue());
		}
		printf("\n");
	}
}


Board::Board() {

	generateBoard(-1, 0);
	printBoard();

}
