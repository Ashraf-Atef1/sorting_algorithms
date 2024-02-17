#include "sort.h"

void swap(listint_t **list, listint_t *first_node, listint_t *second_node)
{
	listint_t *tmp_node = second_node->next;

	first_node = second_node->prev;
	second_node->prev = first_node->prev;
	second_node->next = first_node;
	if (first_node->prev)
		first_node->prev->next = second_node;
	else
		*list = second_node;
	first_node->prev = second_node;
	first_node->next = tmp_node;
	if (tmp_node)
		tmp_node->prev = first_node;
	print_list(*list);
}
/**
 * cocktail_sort_list - Sorting a list with a cocktail_sort_list type
 * @list: A list to be sorted
 * Ashraf Atef
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *l_head = list ? *list : NULL;
	listint_t *cur_node = NULL;
	int s_size = 0, l_size = 0, i = 0;

	while (l_head != NULL)
	{
		cur_node = l_head;
		while (cur_node && (!l_size || s_size + i < l_size))
		{
			if (cur_node->next && cur_node->n > cur_node->next->n)
			{
				swap(list, cur_node, cur_node->next);
				continue;
			}
			if (!cur_node->next)
				break;
			cur_node = cur_node->next;
			s_size++;
		}
		l_size = l_size ? l_size : s_size;
		while (cur_node)
		{
			if (cur_node->prev && cur_node->prev->n > cur_node->n)
			{
				swap(list, cur_node->prev, cur_node);
				continue;
			}
			cur_node = cur_node->prev;
			if (!s_size--)
				break;
		}
		l_head = l_head->next;
		i++;
	}
}
