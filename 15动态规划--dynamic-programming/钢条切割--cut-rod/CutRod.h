#ifndef _CUT_ROD_H_
#define _CUT_ROD_H_

int CUT_ROD(const int *price, int length)
{
	int i = 0;
	int q = -1;

	if(length == 0)
		return 0;
	
	for(i = 1; i <=length; i++)
	{
		int tmp_max = price[i] + CUT_ROD(price, length - i)
		if(q < tmp_max)
			q = tmp_max;
	}
	return q;
}

#endif
