#include <stdio.h>
#include <stdbool.h>
#include "sort.h"

/**
 * insertion_sort_list - sorts a linked list
 * @list: linked list pointer
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head, *f_curr, *next, *b_cur, *prev, *hold_ptr;

	if (list == NULL || *list == NULL)
		return;
	f_curr = *list;
	while (f_curr->next != NULL)
	{
		next = f_curr->next;
		if (f_curr->n > next->n)
		{
			b_cur = next;
			while (true)
			{
				prev = b_cur->prev;
				if (prev != NULL && prev->n > b_cur->n)
				{
					hold_ptr = prev->prev;
					prev->prev = b_cur;
					b_cur->prev = hold_ptr;
					hold_ptr != NULL ? (hold_ptr->next = b_cur) : (hold_ptr = NULL);
					prev->next = b_cur->next;
					b_cur->next != NULL ? (b_cur->next->prev = prev) : (b_cur->next = NULL);
					b_cur->next = prev;
					if (b_cur->prev == NULL)
						*list = b_cur;
					head = *list;
					while (head->next != NULL)
					{
						printf("%d, ", head->n);
						head = head->next;
					}
					printf("%d\n", head->n);
				}
				else
					break;
			}
			f_curr = b_cur;
		}
		f_curr = f_curr->next;
	}
}
