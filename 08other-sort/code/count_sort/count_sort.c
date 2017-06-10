#include "count_sort.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void count_sort(int A[], int B[], int n, int k)
{
	int i = 0;
	int *temp = (int *)malloc(sizeof(int) * (k+1));
	memset(temp, 0x00, sizeof(int) * (k+1));
	
	for(i = 0; i < n; i++)
		temp[A[i]]++;

	for(i = 1; i <= k; i++)
		temp[i] = temp[i] + temp[i-1];

	for(i = n-1; i >= 0; i--)
	{
		B[temp[A[i]] - 1] = A[i];
		temp[A[i]] = temp[A[i]] - 1;
	}

	free(temp);
}
