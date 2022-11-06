#include "sort.h"
typedef unsigned char bool;
#define true (1)
#define false (!true)
#define SWAP_DOUBLE_LIST(NODE, HEAD, TYPE)                         \
	do                                                             \
	{                                                              \
		TYPE node_connections[4];                                  \
		node_connections[0] = (NODE)->prev->next;                  \
		node_connections[1] = (NODE)->prev->prev;                  \
		node_connections[2] = (NODE)->next;                        \
		node_connections[3] = (NODE)->prev;                        \
		if (*(HEAD) == node_connections[3])                        \
		{                                                          \
			*(HEAD) = (NODE);                                      \
		}                                                          \
		if (node_connections[3]->prev)                             \
		{                                                          \
			node_connections[3]->prev->next = node_connections[0]; \
		}                                                          \
		if ((NODE)->next)                                          \
		{                                                          \
			(NODE)->next->prev = node_connections[3];              \
		}                                                          \
		node_connections[3]->next = node_connections[2];           \
		node_connections[3]->prev = node_connections[0];           \
		(NODE)->next = node_connections[3];                        \
		(NODE)->prev = node_connections[1];                        \
	} while (false)

#define SWAP_DOUBLE_LIST_NEXT(NODE, HEAD, TYPE)             \
	do                                                      \
	{                                                       \
		TYPE node_connections[4];                           \
		if ((NODE)->prev)                                   \
			node_connections[0] = (NODE)->prev->next;       \
		node_connections[1] = (NODE)->next->next;           \
		node_connections[2] = (NODE)->next;                 \
		node_connections[3] = (NODE);                       \
		if (*(HEAD) == NODE)                                \
		{                                                   \
			*(HEAD) = node_connections[2];                  \
		}                                                   \
		if (NODE->prev)                                     \
		{                                                   \
			(NODE)->prev->next = node_connections[2];       \
		}                                                   \
		if ((NODE)->next->next)                             \
		{                                                   \
			(NODE)->next->next->prev = node_connections[3]; \
		}                                                   \
		(NODE)->next->next = node_connections[3];           \
		(NODE)->next->prev = (NODE)->prev;                  \
		(NODE)->next = node_connections[1];                 \
		(NODE)->prev = node_connections[2];                 \
	} while (false)

/**
 * cocktail_sort_list - sort list using the cocktail algorithm.
 *
 * @list: head of a double linked list.
 *
 * Return: Always void.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *node, *next_node = NULL, *in_node = NULL;
	int changes;

	if (list == NULL || *list == NULL)
		return;
	node = *list;
	for (node = *list; node; node = next_node)
	{
		changes = 0;
		next_node = node->next;
		for (in_node = *list; in_node;)
		{
			if (in_node->next && in_node->next->n < in_node->n)
			{	changes++;
				SWAP_DOUBLE_LIST_NEXT(in_node, list, listint_t *);
				print_list((const listint_t *)*list);
				continue;
			}
			if (in_node->next)
				in_node = in_node->next;
			else
			{
				if (changes != 0)
					break;
				in_node = in_node->next;
			}
		}
		for (; in_node;)
		{
			if (in_node->prev && in_node->n < in_node->prev->n)
			{
				SWAP_DOUBLE_LIST(in_node, list, listint_t *);
				print_list((const listint_t *)*list);
				continue;
			}
			if (in_node->prev == NULL)
				break;
			in_node = in_node->prev;
		}
	}
}
