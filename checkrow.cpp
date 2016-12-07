#include<string>
#include<cstring>
#include<iostream>

using namespace std;

int checkrow(int m, int n, int **a)
{
	int x;
	for (x = 0; x<9; x++)
	{
		if (x != n)
			if (a[m][n] == a[m][x])
				return(0);
	}
	return(1);
}
