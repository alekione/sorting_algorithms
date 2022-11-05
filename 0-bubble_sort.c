#include "stdio.h"
#include <stdbool.h>
#include "sort.h"

/**
 * bubble_sort - sorts an array of integers
 * @array: array containing numbers
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int num;
	bool sorted;

	if (size <= 0)
		return;
	while (true)
	{
		sorted = true;
		for (j = 0; j < size - 1; j++)
		{
			if (*(array + (j + 1)) < *(array + j))
			{
				sorted = false;
				break;
			}
		}
		if (sorted)
			break;
		for (i = 0; i < size - 1; i++)
		{
			if (*(array + (i + 1)) < *(array + i))
			{
				num = *(array + i);
				*(array + i) = *(array + (i + 1));
				*(array + (i + 1)) = num;
				for (j = 0; j < size; j++)
				{
					if (j == size - 1)
						printf("%d\n", *(array + j));
					else
						printf("%d, ", *(array + j));
				}
			}
		}
	}
}
