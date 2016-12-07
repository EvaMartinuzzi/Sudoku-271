#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string>
#include<cstring>
#include<iostream>

using namespace std;

//*just kinda left these out so I could use them throughout the code, not sure if most efficient though*//
int **a = new int *[9];
int r[60][2];
int row, col, icount, m, u, x, n, z;
char c;
int h = 0;
void display(void), generate();
int check_c(int m, int n, int **a);
int checkrow(int m, int n, int **a);
int checkcolumn(int m, int n, int **a);
int check(int m, int n);
int isfixed(int icount, int m, int n);
int userinput();
int mode(int h);

int main()
{
menu:
	for (int i = 0; i < 9; i++)
		a[i] = new int[9];
	cout << "\t\t\t   SUDOKU \n\n\t\t\t" << endl;
	cout << "Select Your Option (enter number):\n     1. Start\n     2. Rules" << endl;
	cin >> c;

	if (c == '1') {
		getchar();
		generate();
		h = mode(h);
	}
	else if (c == '2') {
		cout << "\n\n\t\t\tHOW TO PLAY\n" << endl;
		cout << "\n\nSudoku is a game with a grid of 81 squares, divided into \n nine blocks with nine squares each." << endl;
		cout << "\n\nEach of the nine squares must contain numbers 1 - 9" << endl;
		cout << "\n\nEach number may only appear once in a column, row, or square." << endl;
		cout << "\n\nGood luck!" << endl;
		cout << "Enter any key to continue\n" << endl;
		goto menu;
	}
	else {
		cout << ("Stop that. Press '1' or '2'. There is no third option. Please stop.");
	}
	for (int i = 0; i < row; i++)
		delete[] a[i];
	delete[] a;
}


int isfixed(int count, int m, int n)
{
	int i;
	for (i = 0; i<count; i++)
		if (m == r[i][0] && n == r[i][1])
			return(1);
	return(0);
}


int userinput() {
	row = row + 1;
	col = col + 1;
strt:
	int r = 0; m = 0;
	cout << "Enter the row you would like: " << endl;
	scanf_s("%i", &row);
	
	cout << "Enter the column you would like: " << endl;
	scanf_s("%i", &col);
	
	cout << "What value would you like to enter?" << endl;
	scanf_s("%i", &z);
	
	//if (row >1 && row <10 && col>1 && col<10 && m >1 && m <10){
		if (a[row][col] = z){
			printf("Good work!");
			return a[row][col];
		}
		else{
			printf("Try Again!");
			goto strt;
		}
}


//*Function that prints the Sudoku board*//
void display()
{
	int i, j, k, fixed;

	for (i = 0; i<10; i++) {
		if (i % 3 == 0) {
			if (i != 0) {
				printf("\n");
			}
			printf("\t\t");
			//*makes top and bottom pretty bit*//
			for (k = 0; k < 45; k++) {
				printf("*");
			}
			if (i == 9) {
				goto end;
			}
		}
		//*makes the vertical lines... this I'm not sure about*//
		if (i % 3 != 0)
		{
			printf("\n\t\t");
			printf("|              |              |             |");
			printf("\n\t\t");
		}
		else
			printf("\n\t\t");
		for (j = 0; j<9; j++)
		{
			if (j % 3 == 0)
			{
				if (a[i][j] == 0)
				{

					printf("|");
					for (k = 0; k<4; k++)
						printf(" ");
				}
				else
				{

					printf("| ", a[i][j]);
					fixed = isfixed(icount, i, j);

					printf("%d  ", a[i][j]);
				}
			}
			else
			{
				if (a[i][j] == 0)
					for (k = 0; k<5; k++)
						printf(" ");
				else
				{
					fixed = isfixed(icount, i, j);

					printf("  %d  ", a[i][j]);
				}
			}
		}
		printf("\b|");
	}end:
	//*when finished*//
	printf("\n\t\tPress Enter key to exit.");
}




//*Funtion that checks if numbers are consistent, using other check fns*//
int check(int m, int n)
{
	int c;
	c = check_c(m, n, a);
	if (c == 1)
		c = c*checkrow(m, n, a);
	else
		return(c);
	if (c == 1)
		c = c*checkcolumn(m, n, a);
	else
		return(c);
	return(c);
}

//*This is the Sudoku solver function*//
//*this was a bitch, man*//
int solve()
{
	int m = 0, n = 0, number, c, fixed;

A:

	for (m = row; m<9; m++)
	{
		n = col;
		while (n<9)
		{
			number = 1;
			fixed = isfixed(icount, m, n);
			if (fixed == 0)
			{
			allot:
				a[m][n] = number;
				c = check(m, n);
				if (c == 0)
				{
					number++;
					if (number>9)
					{
						a[m][n] = 0;
						if (n == 0)
						{
							row = m - 1; col = 8;
							if (row<0)
								return(0);
							goto B;
						}
						else
						{
							row = m; col = n - 1;
							if (row<0 || col<0)
								return(0);
							goto B;
						}
					}
					goto allot;
				}
			}
			n++;
			if (n>8)
				col = 0;
		}
	}
	return(1);

B:

	fixed = isfixed(icount, row, col);
	if (fixed == 0)
	{
		number = a[row][col];
	allot1:
		number++;
		a[row][col] = number;
		if (number>9)
		{
			a[row][col] = 0;
			if (col == 0)
			{
				row--; col = 8;
				if (row<0)
					return(0);
				goto B;
			}
			else
			{
				col--;
				if (col<0)
					return(0);
				goto B;
			}
		}
		c = check(row, col);
		if (c == 0)
			goto allot1;
		else
		{
			if (col == 8)
			{
				row++;
				if (row>8)
					return(0);
				col = 0;
				goto A;
			}
			else
			{
				col++;
				if (col>8)
					return(0);
				goto A;
			}
		}
	}
	else
	{
		if (col == 0)
		{
			row--; col = 8;
			if (row<0)
				return(0);
			goto B;
		}
		else
		{
			col--;
			if (col<0)
				return(0);
			goto B;
		}
	}
}

//*This function does the actual creation bit of the sudoku*//
void generate()
{
	int b[9][9];
	int c, i, m, n;
	int count = 1;
	int fixed, error;
	char choice;
	rand();
generate:

	for (m = 0; m < 9; m++) {
		for (n = 0; n < 9; n++) {
			a[m][n] = 0;
		}
	}

	for (i = 0; i<60; i++) {
		r[i][0] = 20; r[i][1] = 20;
	}

	//*Difficulty*//
	cout << ("\n\n\n\n\t\tEnter your difficulty");
	cout << ("\n\n\n\t\t1.'I literally don't know what a puzzle is'\n\n\t\t2.Easy\n\n\t\t3.Medium\n\n\t\t4.Hard\n\n\n\t\tENTER: ");
	//*takes the user's input*//
	scanf_s("%c", &choice);

	switch (choice)
	{
		//*beginner mode*//
	case '1': x = 32 + rand() % 5;
		break;
		//*easy mode*//
	case '2': x = 28 + rand() % 5;
		break;
		//*medium mode*//
	case '3': x = 24 + rand() % 3;
		break;
		//*hard mode*//
	case '4': x = 19 + rand() % 3;
		break;
		//*if they enter something else, go up to 'generate'*//
	default: getchar();
		goto generate;
	}

	a[0][0] = 1 + rand() % 9; r[0][0] = 0; r[0][1] = 0;

	//*iterating through, making random #s*//
	for (count = 1; count<10; count++)
	{
	choose:
		m = rand() % 10; n = rand() % 10;
		fixed = isfixed(icount, m, n);
		if (fixed == 1)
			goto choose;
		r[count][0] = m; r[count][1] = n;
	allot:
		a[m][n] = 1 + rand() % 10;
		if (a[m][n] == 0)
			goto allot;
		c = check(m, n);
		if (c == 0)
			goto allot;
	}

	icount = count;
	error = solve();

	for (m = 0; m < 9; m++) {
		for (n = 0; n < 9; n++) {
			b[m][n] = a[m][n];
		}
	}

	row = 0; col = 0;

	for (i = 0; i<60; i++) {
		r[i][0] = 20; r[i][1] = 20;
	}

	if (error == 0) {
		goto generate;
	}

	for (count = 0; count<x / 2; count++) {
	choose2:
		m = rand() % 10; n = rand() % 6;
		fixed = isfixed(count, m, n);
		if (fixed == 1) {
			goto choose2;
		}
		r[count][0] = m; r[count][1] = n;
		r[count + x / 2][0] = 8 - m;
		r[count + x / 2][1] = 8 - n;
	}

	for (m = 0; m < 9; m++) {
		for (n = 0; n < 9; n++) {
			fixed = isfixed(x, m, n);
			if (fixed != 1) {
				a[m][n] = 0;
			}
		}
	}

	icount = x;
	display();
	getchar();
	cout << "\n\n\n\tEnter 's' to solve the puzzle or 'm' to generate another puzzle, 'u' to input values, and 'h' to get a hint: " << endl;
	scanf_s("%c", &choice);

	//*if they wish to solve, upper or lower case*//
	if (choice == 's' || choice == 'S')
	{
		for (m = 0; m < 9; m++) {
			for (n = 0; n < 9; n++) {
				a[m][n] = b[m][n];
			}
		}
		display();
		getchar();
	}
	getchar();
	system("pause");
	if (choice == 'u' || choice == 'U') {
		for (m = 0; m < 9; m++) {
			for (n = 0; n < 9; n++) {
				a[m][n] = b[m][n];
			}
		}
		userinput();
	}
	//*otherwise make a new puzzle*//
	if (choice == 'm' || choice == 'M')
		goto generate;
	exit(0);
}
