#include "sort.h"
/**
 * swap - swap to list nodes then print this doubly linked list
 * @list: A doubly linked list
 * @first_node: first node pointer to swap
 * @second_node: second node pointer to swap
 * Ashraf Atef
 */
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

	while (l_head != NULL)
	{
		cur_node = l_head;
		while (cur_node)
		{
			if (cur_node->next && cur_node->n > cur_node->next->n)
			{
				swap(list, cur_node, cur_node->next);
				continue;
			}
			if (!cur_node->next)
				break;
			cur_node = cur_node->next;
		}
		while (cur_node)
		{
			if (cur_node->prev && cur_node->prev->n > cur_node->n)
			{
				swap(list, cur_node->prev, cur_node);
				continue;
			}
			cur_node = cur_node->prev;
		}
		l_head = l_head->next;
	}
}
