#include <stdio.h>
#include <stdlib.h>

#include "CutRod.h"

int main()
{
	int price[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
	int i = 0;
	int num = sizeof(price)/sizeof(int);

    for(i = 0; i < num; i++)
    {
        int q = CUT_ROD(price, i+1);
        printf("length = %d, the best price is %d\n", (i+1), q);
	}

	getchar();
	return 0;
}
