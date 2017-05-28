#ifndef FIND_MAXIMUM_SUBARRAY_H_
#define FIND_MAXIMUM_SUBARRAY_H_

typedef struct _subarray{
	int low;
	int high;
	int sum;
}subarray;

subarray find_maximum_subarray(int A[], int low, int high);

#endif
