#include "sort.h"

/**
 * insertion_sort_list - Sorting a list with a insertion_sort type
 * @list: A list to be sorted
 * Ashraf Atef
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *l_head = list && *list ? (*list)->next : NULL;
	listint_t *cur_node = NULL;
	listint_t *prev_node = NULL;
	listint_t *tmp_node = NULL;

	while (l_head != NULL)
	{
		cur_node = l_head;
		while (cur_node && cur_node->prev && cur_node->n < cur_node->prev->n)
		{
			tmp_node = cur_node->next;
			prev_node = cur_node->prev;
			cur_node->prev = prev_node->prev;
			cur_node->next = prev_node;
			if (prev_node->prev)
				prev_node->prev->next = cur_node;
			else
				*list = cur_node;
			prev_node->prev = cur_node;
			prev_node->next = tmp_node;
			if (tmp_node)
				tmp_node->prev = prev_node;
			print_list(*list);
		}
		l_head = l_head->next;
	}
}
