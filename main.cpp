#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <cstring>
#include <iostream>
#include "Board.h"
#include "Square.h"
#include <list>
#include <fstream>

using namespace std;

//declaring global functions
void displayRules();
void loadMenu(Board &sudoku);
void user_interface(Board &sudoku);
void clearBoard(Board &sudoku);

int main(int argv, char **argc) {
    
    Board sudoku;
    loadMenu(sudoku);
    
    /*user_interface();
    loadMenu();
    Board sudoku;
    int guess;
    cout << "Wanna make a guess? Yes, press '1'" << endl;
    cin >> guess;
    
    /*switch (guess){
     case'1':
     editSquare(sudoku,1,1);
     }*/
    system("pause");
    return 0;
}


void displayRules() {
    cout << "\n\n\t\t\tHOW TO PLAY\n" << endl;
    cout << "\n\nSudoku is a game with a grid of 81 squares, divided into \n nine blocks with nine squares each." << endl;
    cout << "\n\nEach of the nine squares must contain numbers 1 - 9" << endl;
    cout << "\n\nEach number may only appear once in a column, row, or square." << endl;
    cout << "\n\nGood luck!" << endl;
    cout << "Enter any key to continue\n" << endl;
}


void user_interface(Board& sudoku) {
    
    int x,y,n;
    cout << "Enter the row you would like to enter your value in" << endl;
    cin>>x;
    cout <<"Enter the column you would like to enter a value in" << endl;
    cin>>y;
    cout << "Enter a value" << endl;
    cin>>n;
    sudoku.inputTile(x, y, n);
}



void clearBoard(Board &sudoku_board)
{
    
    for (int i = 0; i < 81; i++)
        if (!sudoku_board.isFixedValue[i])
            sudoku_board.values[i] = 0;
    return;
}


void loadMenu(Board &sudoku) {
    
    int selection;
    
    cout << "Select Your Option (enter number):\n" << endl;
    cout << "\t1. Start\n" << endl;
    cout << "\t2. Rules\n" << endl;
    
    cin >> selection;
    
    switch (selection) {
        case 1:
            cout << "Generating board" << endl;
            sudoku.generateBoard(0,0);
            
            break;
        case 2:
            displayRules();
            loadMenu(sudoku);
            break;
        default:
            cout << ("Stop that. Press '1' or '2'. There is no third option. Please stop.") << endl;
            break;
    }
}

