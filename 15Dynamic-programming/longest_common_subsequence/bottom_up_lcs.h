#ifndef BOTTOM_UP_LCS_H_
#define BOTTOM_UP_LCS_H_

#include <string.h>

#define MAX_LENGTH 128

static int c[MAX_LENGTH][MAX_LENGTH] = {0};
static char b[MAX_LENGTH][MAX_LENGTH] = {0};

void bottom_up_lcs(const char *x, const char *y)
{
	int m = strlen(x);
	int n = strlen(y);

	int i = 0, j = 0;

	for(i = 1; i <= m; i++)
	{
		for(j = 1; j <= n; j++)
		{
			if(x[i-1] == y[j-1])
			{
				c[i][j] = c[i-1][j-1] + 1;
				b[i][j] = '\\';
			}
			else if(c[i-1][j] >= c[i][j-1])
			{
				c[i][j] = c[i-1][j];
				b[i][j] = '|';
			}
			else
			{
				c[i][j] = c[i][j-1];
				b[i][j] = '-';
			}
		}
	}
}
void print_b(int xlength, int ylength)
{
	int i = 0, j = 0;

	for(i = 1; i <= xlength; i++)
	{
		for(j = 1; j <= ylength; j++)
		{
			printf("%c ", b[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void print_c(int xlength, int ylength)
{
	int i = 0, j = 0;

	for(i = 0; i <= xlength; i++)
	{
		for(j = 0; j <= ylength; j++)
		{
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void print_lcs(const char *x, int xlength, int ylength)
{
	if(xlength == 0 || ylength == 0)
		return;

	if(b[xlength][ylength] == '\\')
	{
		print_lcs(x, xlength-1, ylength-1);
		printf("%c", x[xlength-1]);
	}
	else if(b[xlength][ylength] == '|')
	{
		print_lcs(x, xlength-1, ylength);
	}
	else
	{
		print_lcs(x, xlength, ylength-1);
	}	
}

#endif
