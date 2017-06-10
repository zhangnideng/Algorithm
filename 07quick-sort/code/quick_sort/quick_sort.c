#include "quick_sort.h"
#include <stdio.h>
#include <stdlib.h>

static void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void quicksort(int A[], int left, int right)
{
	if(left < right)
	{
		int temp = A[right];
		int i = left - 1, j = left;

		for(j = left; j < right; j++)
		{
			if(A[j] < temp)
			{
				i++;
				if(i != j)
				{
					swap(&A[i], &A[j]);
				}
			}
		}

		swap(&A[i+1], &A[right]);
		
		quicksort(A, left, i);
		quicksort(A, i+2, right);
	}
}

void random_quicksort(int A[], int left, int right)
{
	srand((unsigned int)time(0));
	if(left < right)
	{
		{
			int tmp = rand() % (right - left + 1) + left;
			if(tmp != right)
				swap(&A[tmp], &A[right]);
		}
		int temp = A[right];
		int i = left - 1, j = left;

		for(j = left; j < right; j++)
		{
			if(A[j] < temp)
			{
				i++;
				if(i != j)
					swap(&A[i], &A[j]);
			}
		}

		swap(&A[i+1], &A[right]);

		quicksort(A, left, i);
		quicksort(A, i+2, right);
	}
}

void three_quicksort(int A[], int left, int right)
{

}

void quick_quicksort(int A[], int left, int right)
{

}
