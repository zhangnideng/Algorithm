#include <stdio.h>
#include <stdlib.h>
#include "bucket_sort.h"

typedef struct node{
	int key;
	struct node *next;
}bucket, *bucket_list;

static void insert(bucket_list *list, int n)
{
	bucket_list tmp1 = *list, tmp2 = *list;
	
	bucket_list new = (bucket_list)malloc(sizeof(bucket));
	if(new == NULL)
	{
		printf("insert: out of space\n");
		return;
	}
	new->key = n;
	new->next = NULL;

	if(*list == NULL)
	{
		*list = new;
	}
	else
	{
		while(tmp1 != NULL && tmp1->key < n)
		{
			tmp2 = tmp1;
			tmp1 = tmp1->next;
		}

		if(tmp1 == tmp2)
		{
			new->next = tmp1;
			*list = new;
		}
		else
		{
			tmp2->next = new;
			new->next = tmp1;
		}
	}
}

void bucket_sort(int A[], int n, int size)
{
	int i = 0, j = 0;
	bucket_list *list = (bucket_list*)malloc(sizeof(bucket_list) * size);
	if(list == NULL)
	{
		return;
	}
	for(i = 0; i < size; i++)
		list[i] = NULL;

	for(i = 0; i < n; i++)
	{
		insert(&list[(A[i] - 1)/10], A[i]);
	}

	for(i = 0; i < size; i++)
	{
		while(list[i] != NULL)
		{
			bucket_list tmp = list[i];
			A[j++] = list[i]->key;
			list[i] = list[i]->next;
			free(tmp);
			tmp = NULL;
		}
	}

	free(list);
}
