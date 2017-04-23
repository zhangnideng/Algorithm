#include <stdio.h>
#include "recursive_activity_selector.h"

int main()
{
	int start[] = {0, 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
	int finish[] = {0, 4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};
	int n = sizeof(start) / sizeof(int);

	recursive_activity_selector(start, finish, 0, n-1);
	activity_get_number();

	return 0;
}
