#ifndef MEMOIZED_MATRIX_CHAIN_
#define MEMOIZED_MATRIX_CHAIN_

#define MAX_LENGTH 128
#define MAX 65535
static matrix[MAX_LENGTH][MAX_LENGTH] = {0};
static s[MAX_LENGTH][MAX_LENGTH] = {0};

void memoized_matrix_chain(const char *p, int length)
{
	int l = 0, i = 0, j = 0, k = 0;
	int q = -1;

	for(l = 2; l <= length; l++)
	{
		for(i = 1; i <= length - l + 1; i++)
		{
			j = i+l-1;
			matrix[i][j] = MAX;
			for(k = i; k <= j-1; k++)
			{
				q = matrix[i][k]+matrix[k+1][j] + p[i-1]*p[k]*p[j]
				if(q < matrix[i][j])
				{
					matrix[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
}

#endif
