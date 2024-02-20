#include "deck.h"

/**
 * swap - swap to list nodes then print this doubly linked list
 * @list: A doubly linked list
 * @first_node: first node pointer to swap
 * @second_node: second node pointer to swap
 * Ashraf Atef
 */
void swap(deck_node_t **list, deck_node_t *first_node, deck_node_t *second_node)
{
	deck_node_t *tmp_node = second_node->next;

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
}
int value_to_int(const char *str)
{
	switch (*str)
	{
	case 'A':
		return (1);
	case '1':
		return (10);
	case '2':
		return (2);
	case '3':
		return (3);
	case '4':
		return (4);
	case '5':
		return (5);
	case '6':
		return (6);
	case '7':
		return (7);
	case '8':
		return (8);
	case '9':
		return (9);
	case 'J':
		return (11);
	case 'Q':
		return (12);
	case 'K':
		return (13);
	}
	return (0);
}
int nodes_compare(card_t first, card_t second)
{

	if (first.kind == second.kind &&
		value_to_int(first.value) > value_to_int(second.value))
		return (1);
	else if (first.kind > second.kind)
		return (1);
	else
		return (0);
}
/**
 * cocktail_sort_list_core - the core function
 * of the cocktail_sort_list function
 * @list: linked list
 * @head: the head of the linked list
 * @cur_node: the current node;
 * @tail: the tail of the linked list
 * Ashraf Atef
 */
void cocktail_sort_list_core(deck_node_t **list, deck_node_t *head,
							 deck_node_t *cur_node, deck_node_t *tail)
{
	int notSorted = 1;

	while (notSorted)
	{
		notSorted = 0, cur_node = head;
		while (cur_node != tail)
		{
			if (nodes_compare(*cur_node->card, *cur_node->next->card))
			{
				if (cur_node->next == tail)
					tail = cur_node;
				if (cur_node == head)
					head = cur_node->next;
				swap(list, cur_node, cur_node->next), notSorted = 1;
				continue;
			}
			cur_node = cur_node->next;
		}
		while (cur_node != head)
		{
			if (nodes_compare(*cur_node->prev->card, *cur_node->card))
			{
				if (cur_node->prev == head)
					head = cur_node;
				if (cur_node == tail)
					tail = cur_node->prev;
				swap(list, cur_node->prev, cur_node), notSorted = 1;
				continue;
			}
			cur_node = cur_node->prev;
		}
		if (head->next == tail)
			break;
		tail = tail->prev, head = head->next;
	}
}
/**
 * cocktail_sort_list - Sorting a list with a cocktail_sort_list type
 * @list: A list to be sorted
 * Ashraf Atef
 */
void cocktail_sort_list(deck_node_t **list)
{
	deck_node_t *head = NULL, *cur_node = NULL, *tail = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	head = cur_node = *list;
	for (tail = *list; tail->next != NULL;)
		tail = tail->next;
	cocktail_sort_list_core(list, head, cur_node, tail);
}
/**
 * sort_deck - Sorting a deck array.
 * @deck: An array to be sorted
 * Ashraf Atef
 */
void sort_deck(deck_node_t **deck)
{
	cocktail_sort_list(deck);
}