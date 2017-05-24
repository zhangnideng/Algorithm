#include <stdio.h>
#include "insertion/insertion-sort.h"
#include "merge/merge_sort.h"

static print_array(int A[], int length)
{
	int i = 0;

	for(i = 0; i < length; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
	int i = 0;
	int a1[] = {2, 4, 7, 5, 6, 3, 2, 1};
	int a2[] = {2, 4, 7, 5, 6, 3, 2, 1};
	int length = sizeof(a1) / sizeof(int);

	{
		printf("\nbefore insertion-sort:");
		print_array(a1, length);

		insertion_sort(a1, length);

		printf("after  insertion-sort:");
		print_array(a1, length);
	}

	{
		printf("\nbefore merge-sort:");
		print_array(a2, length);

		merge_sort(a2, 0, length - 1);

		printf("after merge-sort:");
		print_array(a2, length);
	}

	return 0;
}
