#include <stdio.h>
#include "insertion/insertion-sort.h"

int main(int argc, char *argv[])
{
	int i = 0;
	int a[] = {5, 2, 4, 6, 1, 3};
	int length = sizeof(a) / sizeof(int);

	printf("before sort:");
	for(i = 0; i < length; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	insertion_sort(a, length);

	printf("after  sort:");
	for(i = 0; i < length; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}
