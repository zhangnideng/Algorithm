#include <stdio.h>
#include <stdlib.h>

static int compare(const void *a, const void *b)
{
	return (*(int*)a - *(int*)b);
}

int random_select(int A[], int left, int right, int i);

int main()
{
	int i = 0;
	int a1[] = {13, 19, 9, 5, 12, 8, 7, 4, 21, 2, 6, 11};
	int a2[] = {13, 19, 9, 5, 12, 8, 7, 4, 21, 2, 6, 11};

	int length = sizeof(a1)/sizeof(int);

	printf("\nquick_sort\n");
	printf("before sort: ");
	for(i = 0; i < length; i++)
		printf("%d ", a1[i]);
	printf("\n");

	qsort(a1, length, sizeof(int), compare);

	printf("after sort: ");
	for(i = 0; i < length; i++)
		printf("%d ", a1[i]);
	printf("\n");

	for(i = 0; i < length; i++)
		printf("%d: %d\n", i+1, a1[i]);
	printf("\n");

	for(i = 1; i <= length; i++)
	{
		int result = random_select(a2, 0, length - 1, i);
		printf("%d: %d\n", i, result);
	}
	printf("\n");

	return 0;
}

int random_select(int A[], int left, int right, int n)
{
	if(left == right)
		return A[left];
	
	int t = left;
	{
		int tmp = rand() % (right - left + 1) + left;
		if(tmp != right)
		{
			int temp = A[tmp];
			A[tmp] = A[right];
			A[right] = temp;
		}

		int i = left, j = left - 1;
		for(i = left; i < right; i++)
		{
			if(A[i] < A[right])
			{
				j++;
				int temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}

		{
			int temp = A[j+1];
			A[j+1] = A[right];
			A[right] = temp;
		}
		t = j;
	}

	int k = (t+1) - left + 1;
	if(n == k)
		return A[t+1];
	else if(n < k)
		return random_select(A, left, t, n);
	else
		return random_select(A, t+2, right, n-k);
}
