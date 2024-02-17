#include "hash_tables.h"

/**
 * hash_table_get - Retrieve an element from the hash table
 * @ht: A pointer to the hash table
 * @key: The key
 *
 * Return: On success - the value associated with the element
 *	   On failure - "NULL"
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *tmp;

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
