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
	listint_t *head = NULL;
	listint_t *cur_node = NULL, *tail = NULL;
	int notSorted = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	head = cur_node = *list;
	for (tail = *list; tail->next != NULL;)
		tail = tail->next;
	while (notSorted)
	{
		notSorted = 0;
		cur_node = head;
		while (cur_node != tail)
		{
			if (cur_node->n > cur_node->next->n)
			{
				if (cur_node->next == tail)
					tail = cur_node;
				if (cur_node == head)
					head = cur_node->next;
				swap(list, cur_node, cur_node->next);
				notSorted = 1;
				continue;
			}
			cur_node = cur_node->next;
		}
		while (cur_node != head)
		{
			if (cur_node->prev->n > cur_node->n)
			{
				if (cur_node->prev == head)
					head = cur_node;
				if (cur_node == tail)
					tail = cur_node->prev;
				swap(list, cur_node->prev, cur_node);
				notSorted = 1;
				continue;
			}
			cur_node = cur_node->prev;
		}
		if (head->next == tail)
			break;
		tail = tail->prev;
		head = head->next;
	}
}
