#include <stdio.h>
#include "insertion-sort.h"

#define DEBUG

#ifdef DEBUG

#define PRINTF(format, ...) printf(format, ##__VA_ARGS__)

#else

#define PRINTF(format, ...)

#endif

static void print_array(int A[], int n);

void insertion_sort(int A[], int n)
{
	int i = 0, j = 0, temp = A[0];

	for(i = 1; i < n; i++)
	{
		temp = A[i];
		for(j = i-1; j >= 0 && (A[j] > temp); j--)
		{
			A[j+1] = A[j];
		}
		A[j+1] = temp;
		print_array(A, n);
	}
}

static void print_array(int A[], int n)
{
	int i = 0;

	PRINTF("current array: ");
	for(i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}
	PRINTF("\n");
}
