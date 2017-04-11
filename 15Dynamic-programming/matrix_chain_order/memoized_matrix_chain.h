#ifndef MEMOIZED_MATRIX_CHAIN_H_
#define MEMOIZED_MATRIX_CHAIN_H_

#include <stdio.h>

#define MAX_LENGTH2 128
#define MAX2 0xfffffff
static int matrix2[MAX_LENGTH2][MAX_LENGTH2] = {0};
static int s2[MAX_LENGTH2][MAX_LENGTH2] = {0};

int memoized_matrix_chain(const int *p, int left, int right)
{
	if(left == right)
		return 0;
	else if(matrix2[left][right] > 0)
		return matrix2[left][right];
	
	int i = 0, j = 0, k =0;

	for(i = left; i < right; i++)
	{
		for(j = i+1; j <= right; j++)
		{
			matrix2[i][j] = MAX2;
			for(k = i; k <= j-1; k++)
			{
				int tmp = memoized_matrix_chain(p, i, k) + memoized_matrix_chain(p, k+1, j) + p[i-1]*p[k]*p[j];
				if(matrix2[i][j] > tmp)
				{
					matrix2[i][j] = tmp;
					s2[i][j] = k;
				}
			}
		}
	}
}

void memoized_print_optimal_parens(int i, int j)
{
	if(i == j)
		printf("A[%d]", i);
	else
	{
		printf("(");
		memoized_print_optimal_parens(i, s2[i][j]);
		memoized_print_optimal_parens(s2[i][j]+1, j);
		printf(")");
	}
}

void memoized_print_s(int length)
{
	int i = 0, j = 0;

	for(i = 0; i <= length - 1; i++)
	{
		for(j = 0; j <= length - 1; j++)
		{
			printf("%d ", s2[i][j]);
		}
		printf("\n");
	}
}

#endif
