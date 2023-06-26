#include "sort.h"

/**
 * swapfunc - swaps two elements in a doubly linked list
 * @list: linked list
 * @to_swap: element to swap
 * @compare: element to swap, place before to_swap
 * Return: nothing
 */
void swapfunc(listint_t **list, listint_t *to_swap, listint_t *compare)
{
	listint_t *tempp;

	if (compare->next == to_swap)
	{
		if (to_swap->next)
			(to_swap->next)->prev = compare;
		tempp = to_swap->next;
		to_swap->next = compare;
		compare->next = tempp;
		tempp = to_swap->prev;
		to_swap->prev = compare->prev;
		compare->prev = to_swap;
	}
	else
	{
		if (to_swap->next)
			(to_swap->next->prev) = compare;
		(to_swap->prev)->next = compare;
		(compare->next)->prev = to_swap;
		tempp = to_swap->next;
		to_swap->next = compare->next;
		compare->next = tempp;
		tempp = to_swap->prev;
		to_swap->prev = compare->prev;
		compare->prev = tempp;
	}
	if (to_swap->prev)
		(to_swap->prev)->next = to_swap;
	else
		*list = to_swap;
}

/**
 * insertion_sort_list - sorts a linked list
 * @list: a linked list
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *to_swap, *compare;

	if (!list || !*list || (*list)->next == NULL)
		return;

	temp = *list;
	while (temp)
	{
		to_swap = temp;
		compare = temp->prev;
		temp = temp->next;
		while (compare && (compare->n > to_swap->n))
		{
			swapfunc(list, to_swap, compare);
			compare = to_swap->prev;
			print_list(*list);
		}
	}
}
