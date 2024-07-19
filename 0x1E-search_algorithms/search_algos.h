#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

/* "Header files" */
#include <stdio.h>

/* "Structs" */
/**
 * struct listint_s - singly linked list
 *
 * @n: Integer
 * @index: Index of the node in the list
 * @next: Pointer to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct listint_s
{
	int n;
	size_t index;
	struct listint_s *next;
} listint_t;
/**
 * struct skiplist_s - Singly linked list with an express lane
 *
 * @n: Integer
 * @index: Index of the node in the list
 * @next: Pointer to the next node
 * @express: Pointer to the next node in the express lane
 *
 * Description: singly linked list node structure with an express lane
 */
typedef struct skiplist_s
{
	int n;
	size_t index;
	struct skiplist_s *next;
	struct skiplist_s *express;
} skiplist_t;

/* "Functions" */
/**
 * linear_search - The linear search algorithm
 * @array: A pointer to the first element of the array to search in
 * @size: The number of elements in array
 * @value: The value to search for
 *
 * Return: If the value is pesent - The index where value is located
 *	   Otherwise - "-1"
 */
int linear_search(int *array, size_t size, int value);
/**
 * binary_search - The binary search algorithm
 * @array: A pointer to the first element of the array to search in
 * @size: The number of elements in array
 * @value: The value to search for
 *
 * Return: If the value is pesent - The index where value is located
 *	   Otherwise - "-1"
 */
int binary_search(int *array, size_t size, int value);
/**
 * jump_search - The jump search algorithm
 * @array: A pointer to the first element of the array to search in
 * @size: The number of elements in array
 * @value: The value to search for
 *
 * Return: If the value is pesent - The index where value is located
 *	   Otherwise - "-1"
 */
int jump_search(int *array, size_t size, int value);
/**
 * interpolation_search - The interpolation search algorithm
 * @array: A pointer to the first element of the array to search in
 * @size: The number of elements in array
 * @value: The value to search for
 *
 * Return: If the value is pesent - The index where value is located
 *	   Otherwise - "-1"
 */
int interpolation_search(int *array, size_t size, int value);
/**
 * exponential_search - The exponential search algorithm
 * @array: A pointer to the first element of the array to search in
 * @size: The number of elements in array
 * @value: The value to search for
 *
 * Return: If the value is pesent - The index where value is located
 *	   Otherwise - "-1"
 */
int exponential_search(int *array, size_t size, int value);
/**
 * advanced_binary - The advanced binary search algorithm
 * @array: A pointer to the first element of the array to search in
 * @size: The number of elements in array
 * @value: The value to search for
 *
 * Return: If the value is pesent - The index where value is located
 *	   Otherwise - "-1"
 */
int advanced_binary(int *array, size_t size, int value);
/**
 * jump_list - The jump search algorithm in a singly linked list
 * @list: A pointer to the head of the list to search in
 * @size: The number of nodes in list
 * @value: The value to search for
 *
 * Return: If the value is pesent - The index where value is located
 *	   Otherwise - "-1"
 */
listint_t *jump_list(listint_t *list, size_t size, int value);
/**
 * linear_skip - The jump search algorithm in a skip list
 * @list: A pointer to the head of the list to search in
 * @value: The value to search for
 *
 * Return: If the value is pesent - The index where value is located
 *	   Otherwise - "-1"
 */
skiplist_t *linear_skip(skiplist_t *list, int value);

#endif /* SEARCH_ALGOS_H */
