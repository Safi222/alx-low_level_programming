#include "hash_tables.h"


/**
 * hash_table_set - Add an element to the hash table
 * @ht: A pointer to the hash table
 * @key: The key - it cannot be an empty string
 * @value: The value value associated with the key
 *
 * Return: On success - 1
 *	   On failure - 0
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *new, *tmp;

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

	new = malloc(sizeof(hash_node_t));
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

	return (1);
}
