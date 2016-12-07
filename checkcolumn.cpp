#include<string>
#include<cstring>
#include<iostream>

using namespace std;

int checkcolumn(int m, int n, int **a)
{
	int x;
	for (x = 0; x<9; x++)
	{
		if (x != m)
			if (a[m][n] == a[x][n])
				return(0);
	}
	return(1);
}
