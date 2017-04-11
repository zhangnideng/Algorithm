#ifndef BOTTOM_UP_MATRIX_CHAIN_H_
#define BOTTOM_UP_MATRIX_CHAIN_H_

#include <stdio.h>

#define MAX_LENGTH1 128
#define MAX1 0xfffffff
static int matrix[MAX_LENGTH1][MAX_LENGTH1] = {0};
static int s[MAX_LENGTH1][MAX_LENGTH1] = {0};

void bottom_up_matrix_chain(const int *p, int length)
{
	int l = 0, i = 0, j = 0, k = 0;
	int q = -1;

	for(l = 2; l < length; l++)
	{
		for(i = 1; i <= length - l; i++)
		{
			j = i+l-1;
			matrix[i][j] = (unsigned int)MAX1;
			printf("m[%d, %d]\n", i, j);
			for(k = i; k <= j-1; k++)
			{
				printf("m[%d, %d], m[%d, %d]\n", i, k, k+1, j);
				q = matrix[i][k]+matrix[k+1][j] + p[i-1]*p[k]*p[j];
				printf("q = %d\n", q);
				if(q < matrix[i][j])
				{
					matrix[i][j] = q;
					s[i][j] = k;
					printf("matrix[%d, %d] = %d, s[%d, %d] = %d\n", i, j, q, i, j, k);
				}
			}
		}
	}
}

void bottom_up_print_optimal_parens(int i, int j)
{
	if(i == j)
		printf("A[%d]", i);
	else
	{
		printf("(");
		bottom_up_print_optimal_parens(i, s[i][j]);
		bottom_up_print_optimal_parens(s[i][j]+1, j);
		printf(")");
	}
}

void bottom_up_print_s(int length)
{
	int i = 0, j = 0;

	for(i = 0; i <= length - 1; i++)
	{
		for(j = 0; j <= length - 1; j++)
		{
			printf("%d ", s[i][j]);
		}
		printf("\n");
	}
}

#endif
