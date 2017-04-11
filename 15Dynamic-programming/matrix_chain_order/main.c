#include <stdio.h>
#include "bottom_up_matrix_chain.h"
#include "memoized_matrix_chain.h"

int main()
{
	int p[] = {30, 35, 15, 5, 10, 20, 25};
	int length = sizeof(p)/sizeof(int);

	bottom_up_matrix_chain(p, length);
	bottom_up_print_optimal_parens(1, length-1);
	printf("\n");
	bottom_up_print_s(length);

	memoized_matrix_chain(p, 1, length - 1);
	memoized_print_optimal_parens(1, length - 1);
	printf("\n");
	memoized_print_s(length);

	return 0;
}
