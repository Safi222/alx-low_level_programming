#include "hash_tables.h"


/**
 * shash_table_create - Create a new hash table
 * @size: The size of the hash table
 *
 * Return: On success - A pointer to the newly created hash table
 *	   On failure - "NULL"
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	unsigned long int i;
	shash_table_t *ht;

	if (size <= 0)
		return (NULL);

	ht = malloc(sizeof(shash_table_t));

	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = malloc(size * sizeof(shash_node_t *));

	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		ht->array[i] = NULL;

	ht->shead = NULL;
	ht->stail = NULL;
	return (ht);
}

/**
 * sorted_insert - Insert the new node in the sorted list at the right place
 * @ht: A pointer to the hash table
 * @node: A pointer to the newly created node
 *
 * Return: void
 */
void sorted_insert(shash_table_t *ht, shash_node_t *node)
{
	shash_node_t *current = ht->shead;

	/* Insert the first node in the list */
	if (!current)
	{
		node->snext = NULL;
		node->sprev = NULL;

		ht->shead = node;
		ht->stail = node;
		return;
	}

	/* Insert the node between two nodes or as the head node*/
	while (current)
	{
		if (strcmp(node->key, current->key) > 0)
		{
			current = current->snext;
			continue;
		}
		node->snext = current;
		node->sprev = current->sprev;
		if (current->sprev)
			current->sprev->snext = node;
		else
			ht->shead = node;
		current->sprev = node;
		return;
	}

	/* Insert the node as the tail node*/
	node->snext = current;
	node->sprev = ht->stail;
	ht->stail->snext = node;
	ht->stail = node;
}

/**
 * shash_table_set - Add an element to the hash table
 * @ht: A pointer to the hash table
 * @key: The key - it cannot be an empty string
 * @value: The value value associated with the key
 *
 * Return: On success - 1
 *	   On failure - 0
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *new, *tmp;

	if (!ht || !key || !(*key) || !value)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[index];

	while (tmp && strcmp(tmp->key, key) != 0)
		tmp = tmp->next;

	if (tmp)
	{
		free(tmp->value);
		tmp->value = strdup(value);
		if (tmp->value)
			return (1);
		return (0);
	}

	new = malloc(sizeof(shash_node_t));
	if (!new)
		return (0);

	new->value = strdup(value);
	new->key = strdup(key);
	if (!(new->key) || !(new->value))
	{
		if (new->value)
			free(new->value);
		free(new);
		return (0);
	}
	new->next = ht->array[index];
	ht->array[index] = new;
	sorted_insert(ht, new);

	return (1);
}

/**
 * shash_table_get - Retrieve an element from the hash table
 * @ht: A pointer to the hash table
 * @key: The key
 *
 * Return: On success - the value associated with the element
 *	   On failure - "NULL"
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *tmp;

	if (!ht || !key || !(*key))
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[index];

	while (tmp && strcmp(tmp->key, key) != 0)
		tmp = tmp->next;

	if (tmp)
		return (tmp->value);
	return (NULL);
}

/**
 * print_list - Print the sorted list from the two
 *		directions based on the "reversed" member
 * @ht: A pointer to the hash table
 * @reversed: If set to 0 - Print the list normally
 *	      Otherwise - Print the list in reverse
 *
 * Return: void
 */
void print_list(const shash_table_t *ht, char reversed)
{
	char *sep = "";
	shash_node_t *tmp;

	if (reversed)
		tmp = ht->stail;
	else
		tmp = ht->shead;

	printf("{");

	while (tmp)
	{
		printf("%s'%s': '%s'", sep, tmp->key, tmp->value);
		sep = ", ";
		if (reversed)
			tmp = tmp->sprev;
		else
			tmp = tmp->snext;
	}
	printf("}\n");

}

/**
 * shash_table_print - Print a hash table using the sorted list
 * @ht: A pointer to the hash table
 *
 * Return: Void
 */
void shash_table_print(const shash_table_t *ht)
{
	if (!ht)
		return;

	print_list(ht, 0);
}

/**
 * shash_table_print_rev - Print a hash table in reverse order
 *			   using the sorted list
 * @ht: A pointer to the hash table
 *
 * Return: Void
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	if (!ht)
		return;

	print_list(ht, 1);
}

/**
 * shash_table_delete - Delete a hash table
 * @ht: A pointer to the hash table
 *
 * Return: Void
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i;
	shash_node_t *head, *tmp;

	if (!ht)
		return;

	for (i = 0; i < ht->size; i++)
	{
		head = ht->array[i];
		while (head)
		{
			tmp = head->next;
			free(head->key);
			free(head->value);
			free(head);
			head = tmp;
		}
	}
	free(ht->array);
	free(ht);
}
