#include <stdio.h>
#include "bottom_up_lcs.h"

int main()
{
	char x[] = "ABCBDAB";
	char y[] = "BDCABA";

	int xlength = strlen(x);
	int ylength = strlen(y);

	bottom_up_lcs(x, y);

	print_b(xlength, ylength);
	print_c(xlength, ylength);
	print_lcs(x, xlength, ylength);
	printf("\n");

	return 0;
}
