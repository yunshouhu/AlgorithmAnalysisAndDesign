#include "RandomNumber.h"
#include<stdio.h>
#include<string.h>
int b[50][50];
int c[50][50];


void lcs_old(char *x, int m, char *y, int n)
{
	int i;
	int j;
	for (i = 1; i <= m; i++)c[i][0] = 0;
	for (i = 1; i <= n; i++)c[0][i] = 0;
	c[0][0] = 0;
	for (i = 1; i <= m; i++)
		for (j = 1; j <= n; j++)
		{
			if (x[i - 1] == y[j - 1])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 1;
			}
			else
				if (c[i - 1][j] > c[i][j - 1])
				{
					c[i][j] = c[i - 1][j];
					b[i][j] = 2;
				}
				else
				{
					c[i][j] = c[i][j - 1];
					b[i][j] = 3;
				}
		}
}
char str[1024];

void show(int i, int j, char*x)
{
	if (i == 0 || j == 0)
		return;
	if (b[i][j] == 1)
	{
		show(i - 1, j - 1, x);
		printf("%c", x[i - 1]);
	}
	else
		if (b[i][j] == 2)
			show(i - 1, j, x);
		else
			show(i, j - 1, x);
}


int main()
{
	char*x = "aabcdababce";
	char*y = "12abcabcdace";
	int m = strlen(x);
	int n = strlen(y);
	int *c[1024];
	int *b[1024];
	lcs_old(x, m, y, n);
	show(m, n, x);
}