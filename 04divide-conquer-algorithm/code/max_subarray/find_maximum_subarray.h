#ifndef FIND_MAXIMUM_SUBARRAY_H_
#define FIND_MAXIMUM_SUBARRAY_H_

typedef struct _subarray{
	int low;
	int high;
	int sum;
}subarray;

subarray find_maximum_subarray_nlogn(int A[], int low, int high);
subarray find_maximum_subarray_n2(int A[], int low, int high);
subarray find_maximum_subarray_n(int A[], int low, int high);

#endif
