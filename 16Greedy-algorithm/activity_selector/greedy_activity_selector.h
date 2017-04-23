#ifndef GREEDY_ACTIVITY_SELECTOR_H_
#define GREEDY_ACTIVITY_SELECTOR_H_

#define MAX_LENGTH1 128

typedef struct _activity_union1{
	int a[MAX_LENGTH1];
	int number;
}activity_union1;

static activity_union1 activity1 = {{0}, 0};

void greedy_activity_selector(const int *s, const int *f, int k, int n)
{
	int m = k+1;
	int i = 0;

	for(i = m; i <= n; i++)
	{
		if(s[i] >= f[k])
		{
			activity1.number++;
			activity1.a[activity1.number] = i;
			k = i;
		}
	}
}

int greedy_get_number()
{
	int i = 0;
	
	for(i = 1; i <= activity1.number; i++)
	{
		printf("Activity %d\n", activity1.a[i]);
	}

	printf("There are %d activities in the union.\n", activity1.number);

	return activity1.number;
}

#endif
