#include "sort.h"
#include <stdio.h>

/**
 * quick_sort - sorts an array using quick sort algorithm
 * @array: array for sorting
 * @size: size of the arrray
 */
void quick_sort(int *array, size_t size)
{
	size_t i, j, ind;
	int num, num2;

	if (size <= 0)
		return;
	for (i = 0; i < size; i++)
	{
		num = num2 = *(array + i);
		ind = i;
		for (j = i; j < size; j++)
		{
			if (*(array + j) < num)
			{
				ind = j;
				num = *(array + j);
			}
		}
		if (ind != i)
		{
			*(array + i) = num;
			*(array + ind) = num2;
			for (j = 0; j < size - 1; j++)
				printf("%d, ", *(array + j));
			printf("%d\n", *(array + j));
		}
	}
}
