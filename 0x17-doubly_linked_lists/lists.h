#ifndef LISTS_H
#define LISTS_H


#include <stdio.h>
#include <stdlib.h>

/**
 * struct dlistint_s - doubly linked list
 * @n: integer
 * @prev: points to the previous node
 * @next: points to the next node
 *
 * Description: doubly linked list node structure
 *
 */
typedef struct dlistint_s
{
	int n;
	struct dlistint_s *prev;
	struct dlistint_s *next;
} dlistint_t;


/**
 * print_dlistint - Print all the elements of a dlistint_t list
 * @h: A pointer to the head of the list
 *
 * Return: The number of nodes
 */
size_t print_dlistint(const dlistint_t *h);

/**
 * dlistint_len - Calculates the number of nodes in a linked list
 * @h: A pointer to the first node in the linked list
 *
 * Return: The number of nodes
 */
size_t dlistint_len(const dlistint_t *h);

/**
 * add_dnodeint - Add a new node at the biginning of a linked list
 * @head: A pointer to a pointer to the first node in the linked list
 * @n: The number to put inside the node
 *
 * Return: A pointer to the head of the linked list
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n);

/**
 * add_dnodeint_end - Add a new node at the end of a linked list
 * @head: A pointer to a pointer to the first node in the linked list
 * @n: The number to put inside the new node
 *
 * Return: A pointer to the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n);

/**
 * free_dlistint - Free a dlistint_t list
 * @head: A pointer to the linked list to be freed
 *
 * Return: void
 */
void free_dlistint(dlistint_t *head);

/**
 * get_dnodeint_at_index - Get the nth node of a dlistint_t linked list
 * @head: A pointer to the head of the list
 * @index: The index of the node to retrieve
 *
 * Return: The nth node of a dlistint_t linked list,
 *	   or NULL if the node does not exist
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index);

/**
 * sum_dlistint - Calculate the sum of all the data (n) of dlistint_t list
 * @head: A pointer to the first node in the linked list
 *
 * Return: The sum of data or 0 if the list is empty
 */
int sum_dlistint(dlistint_t *head);

/**
 * insert_dnodeint_at_index - Insert a new node at the given position
 * @h: A pointer to the head of the list
 * @idx: The index where the new node should be added
 * @n: The data to be put in the index idx
 *
 * Return: The address of the new node,
 *	   or NULL if :
 *	   1-it failed
 *	   2-it is not possible to add the new node at index idx
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n);

/**
 * delete_dnodeint_at_index - Delete the node at the given position
 * @head: A pointer to the head of the list
 * @index: The index where the new node should be deleted
 *
 * Return: If it succeded - 1
 *	   If it failed - -1
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index);

#endif /* LISTS_H */
