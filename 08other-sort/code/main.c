#include <stdio.h>
#include "count_sort.h"

int main()
{
	int i = 0;
	int a1[] = {13, 19, 9, 5, 12, 8, 7, 4, 21, 2, 6, 11};
	int B[15] = {0};

	int length = sizeof(a1)/sizeof(int);

	printf("\ncount_sort\n");
	printf("before sort: ");
	for(i = 0; i < length; i++)
		printf("%d ", a1[i]);
	printf("\n");

	count_sort(a1, B, length, 22);

	printf("after sort: ");
	for(i = 0; i < length; i++)
		printf("%d ", B[i]);
	printf("\n");

	return 0;
}
