#include <stdio.h>
#include "find_maximum_subarray.h"

static subarray find_max_crossing_subarray(int A[], int low, int mid, int high)
{
	int left = 0, right = 0, sum1 = -65534, sum2 = -65534, sum = 0;
	subarray max = {0,0,0};
	int i = 0;
	
	for(i = mid; i >= low; i--)
	{
		sum += A[i];
		if(sum > sum1)
		{
			sum1 = sum;
			left = i;
		}
	}

	sum = 0;
	for(i = mid+1; i <= high; i++)
	{
		sum += A[i];
		if(sum > sum2)
		{
			sum2 = sum;
			right = i;
		}
	}

	max.low = left;
	max.high = right;
	max.sum = sum1 + sum2;

	return max;
}

subarray find_maximum_subarray(int A[], int low, int high)
{
	if(low == high)
	{
		subarray max;
		max.low = low;
		max.high = high;
		max.sum = A[low];
		return max;
	}
	else
	{
		subarray max1 = {0,0,0}, max2 = {0,0,0}, max3 = {0,0,0};
		int mid = (low + high) / 2;
		max1 = find_maximum_subarray(A, low, mid);
		max2 = find_maximum_subarray(A, mid+1, high);
		max3 = find_max_crossing_subarray(A, low, mid, high);

		if(max1.sum >= max2.sum && max1.sum >= max3.sum)
			return max1;
		else if(max2.sum >= max1.sum && max2.sum >= max3.sum)
			return max2;
		else
			return max3;
	}
}
