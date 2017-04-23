#ifndef RECURSIVE_ACTIVITY_SELECTOR_H_
#define RECURSIVE_ACTIVITY_SELECTOR_H_

#define MAX_LENGTH 128

typedef struct _activity_union{
	int a[MAX_LENGTH];
	int number;
}activity_union;

static activity_union activity = {{0}, 0};

void recursive_activity_selector(const int *s, const int *f, int k, int n)
{
	int m = k+1;

	while(m <= n && s[m] < f[k])
	{
		m++;
	}

	if(m <= n)
	{
		activity.number++;
		activity.a[activity.number] = m;
		recursive_activity_selector(s, f, m, n);
	}
	else
		return;
}

int activity_get_number()
{
	int i = 0;
	
	for(i = 1; i <= activity.number; i++)
	{
		printf("Activity %d\n", activity.a[i]);
	}

	printf("There are %d activities in the union.\n", activity.number);

	return activity.number;
}

#endif
