#ifndef _BOTTOM_UP_CUTROD_H_
#define _BOTTOM_UP_CUTROD_H_

#define MAX_LENGTH 128

static int r[MAX_LENGTH] = {0};

int bottom_up_cutrod(const int *price, int length)
{
	int i = 0, j = 0, q = -1;

	if(r[length] > 0)
		return r[length];

	for(j = 1; j <= length; j++)
	{
		for(i = 1; i <= j; i++)
		{
			int tmp = price[i-1] + r[j - i];
			if(q < tmp)
				q = tmp;
		}
		r[j] = q;
	}

	return r[length];
}

#endif
