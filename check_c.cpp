#include<string>
#include<cstring>
#include<iostream>

using namespace std;

int check_c(int m, int n, int **a)
{
	int x, y;
	for (x = (m / 3) * 3; x<((m / 3) * 3 + 3); x++)
		for (y = (n / 3) * 3; y<((n / 3) * 3 + 3); y++)
		{
			if (m != x && n != y)
				if (a[m][n] == a[x][y])
					return(0);
		}
	return(1);
}
