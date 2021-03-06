#ifndef _MEMOIZED_CUTROD_H_
#define _MEMOIZED_CUTROD_H_

#include <string.h>

#define MAX_LENGTH 128

static int r1[MAX_LENGTH] = {0};

int memoized_cutrod(const int *price, int length)
{
	if(r1[MAX_LENGTH - 1] == 0)		//When first call the API, initialize the array.
		memset(r1, -1, MAX_LENGTH * sizeof(int));

	return memoized_cut_rod_aux(price, length, r1);
}

int memoized_cut_rod_aux(const int *price, int length, int *r)
{
	int q = -1;

	if(r[length] >= 0)
		return r[length];

	if(length == 0)
		q = 0;
	else
	{
		int i = 0;
		for(i = 1; i <= length; i++)
		{
			int tmp = price[i-1] + memoized_cut_rod_aux(price, length - i, r);
			if(q < tmp)
				q = tmp; 
		}
	}
	r[length] = q;

	return q;
}

#endif
