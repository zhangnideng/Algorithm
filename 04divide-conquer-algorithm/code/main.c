#include <stdio.h>
#include "find_maximum_subarray.h"

int main()
{
	int i = 0;
	int array1[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
	int array2[] = {-1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12};
	int num1 = sizeof(array1) / sizeof(int);
	int num2 = sizeof(array2) / sizeof(int);
	subarray result = {0, 0, 0};

	printf("nlogn\n");
	result = find_maximum_subarray_nlogn(array1, 0, num1-1);

	for(i = result.low; i <= result.high; i++)
	{
		printf("%d ", array1[i]);
	}
	printf("\n");

	printf("The maximum subarray is %d, [%d - %d]\n", result.sum, result.low, result.high);

	printf("\n");
	result = find_maximum_subarray_nlogn(array2, 0, num2-1);

	for(i = result.low; i <= result.high; i++)
	{
		printf("%d ", array2[i]);
	}
	printf("\n");

	printf("The maximum subarray is %d, [%d - %d]\n", result.sum, result.low, result.high);

	printf("\nn2\n");
	result = find_maximum_subarray_n2(array1, 0, num1-1);

	for(i = result.low; i <= result.high; i++)
	{
		printf("%d ", array1[i]);
	}
	printf("\n");

	printf("The maximum subarray is %d, [%d - %d]\n", result.sum, result.low, result.high);

	printf("\nn\n");
	result = find_maximum_subarray_n(array1, 0, num1-1);

	for(i = result.low; i <= result.high; i++)
	{
		printf("%d ", array1[i]);
	}
	printf("\n");

	printf("The maximum subarray is %d, [%d - %d]\n", result.sum, result.low, result.high);
	return 0;
}
