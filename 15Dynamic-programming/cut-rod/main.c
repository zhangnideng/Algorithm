#include <stdio.h>
#include <stdlib.h>

#include "CutRod.h"
#include "Memoized_cutrod.h"
#include "Bottom_up_cutrod.h"

int main()
{
	int price[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
	int i = 0;
	int num = sizeof(price)/sizeof(int);

    for(i = 0; i < num; i++)
    {
        int q = CUT_ROD(price, i+1);
        printf("CUT-ROD:length = %d, the best price is %d\n", (i+1), q);
	}

	for(i = 0; i < num; i++)
	{
		int q = memoized_cutrod(price, i+1);
		printf("MEMOIZED:length = %d, the best price is %d\n", (i+1), q);
	}

	for(i = 0; i < num; i++)
	{
		int q = bottom_up_cutrod(price, i+1);
		printf("BOTTOM_UP_CUTROD:length = %d, the best price is %d\n", (i+1), q);
	}

	return 0;
}
