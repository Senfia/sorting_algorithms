#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <stdlib.h>

/*struct for linked lists*/
/**
 * struct listint_s - Singly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


/*printing functions*/
void print_list(const listint_t *list);
void print_list_rev(const listint_t *list);
void print_array(const int *array, size_t size);

void bubble_sort(int *array, size_t size);

void insertion_sort_list(listint_t **list);

void selection_sort(int *array, size_t size);

void quick_sort(int *array, size_t size);


#endif