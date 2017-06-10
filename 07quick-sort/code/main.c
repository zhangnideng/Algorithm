#include <stdio.h>
#include "quick_sort.h"

int main()
{
	int i = 0;
	int a1[] = {13, 19, 9, 5, 12, 8, 7, 4, 21, 2, 6, 11};
	int a2[] = {13, 19, 9, 5, 12, 8, 7, 4, 21, 2, 6, 11};
	int a3[] = {13, 19, 9, 5, 12, 8, 7, 4, 21, 2, 6, 11};

	int length = sizeof(a1)/sizeof(int);

	printf("\nquick_sort\n");
	printf("before sort: ");
	for(i = 0; i < length; i++)
		printf("%d ", a1[i]);
	printf("\n");

	quicksort(a1, 0, length-1);

	printf("after sort: ");
	for(i = 0; i < length; i++)
		printf("%d ", a1[i]);
	printf("\n");

	printf("\nrandom_quicksort\n");
	printf("before sort: ");
	for(i = 0; i < length; i++)
		printf("%d ", a2[i]);
	printf("\n");

	random_quicksort(a2, 0, length - 1);

	printf("after sort: ");
	for(i = 0; i < length; i++)
		printf("%d ", a2[i]);
	printf("\n");

	printf("\nquick_quicksort\n");
	printf("before sort: ");
	for(i = 0; i < length; i++)
		printf("%d ", a3[i]);
	printf("\n");

	quick_quicksort(a3, 0, length - 1);

	printf("after sort: ");
	for(i = 0; i < length; i++)
		printf("%d ", a3[i]);
	printf("\n");
	return 0;
}
