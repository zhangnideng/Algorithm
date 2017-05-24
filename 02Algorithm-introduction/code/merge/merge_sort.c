#include <stdio.h>
#include <stdlib.h>
#include "merge_sort.h"

#define MAX_LIMIT 65535

static void merge(int A[], int left, int mid, int right)
{
	int i = 0, j = 0, k = 0;
	int n1 = mid - left + 1;
	int n2 = right - mid;

	int *temp1 = (int *)malloc(sizeof(int) * (n1+1));
	int *temp2 = (int *)malloc(sizeof(int) * (n2+1));

	for(i = 0; i < n1; i++)
		temp1[i] = A[left + i];

	for(i = 0; i < n2; i++)
		temp2[i] = A[mid + 1 + i];
	
	temp1[n1] = MAX_LIMIT;
	temp2[n2] = MAX_LIMIT;

	for(i = 0, j = 0, k = left; k <= right; k++ )
	{
		if(temp1[i] < temp2[j])
		{
			A[k] = temp1[i];
			i++;
		}
		else
		{
			A[k] = temp2[j];
			j++;
		}
	}

	free(temp1);
	free(temp2);
}

void merge_sort(int A[], int left, int right)
{
	if(left < right)
	{
		int mid = (left + right)/2;

		merge_sort(A, left, mid);
		merge_sort(A, mid+1, right);

		merge(A, left, mid, right);
	}
}
