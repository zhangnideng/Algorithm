#include <stdio.h>
#include "find_maximum_subarray.h"

int main()
{
	int i = 0;
	int array[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
	int num = sizeof(array) / sizeof(int);
	subarray result = {0, 0, 0};

	result = find_maximum_subarray(array, 0, num-1);

	for(i = result.low; i <= result.high; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");

	printf("The maximum subarray is %d, [%d - %d]\n", result.sum, result.low, result.high);

	return 0;
}
