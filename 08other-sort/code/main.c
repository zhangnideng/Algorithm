#include <stdio.h>
#include "count_sort.h"

int main()
{
	int i = 0;
	int a1[] = {13, 19, 9, 5, 12, 8, 7, 4, 21, 2, 6, 11};
	int a2[] = {56,45,34,23,12,89,78,67,90,14,36,57,99,25,78,80,64,100,71,87,85,96,59};
	int B[15] = {0};

	int length = sizeof(a1)/sizeof(int);
	int length2 = sizeof(a2)/sizeof(int);

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

	printf("\nbucket_sort\n");
	printf("before sort: ");
	for(i = 0; i < length2; i++)
		printf("%d ", a2[i]);
	printf("\n");

	bucket_sort(a2, length2, 10);

	printf("after sort: ");
	for(i = 0; i < length2; i++)
		printf("%d ", a2[i]);
	printf("\n");
	return 0;
}
