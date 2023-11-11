#include "search.h"
/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: list is a pointer to the head of the skip list to search in
 * @value: value is the value to search for
 * Return: 0
*/
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *new;

	if (list == NULL)
		return (NULL);

	new = list;
	while (new->express != NULL)
	{
		printf("Value checked at index [%ld] = [%d]\n",
		new->express->index, new->express->n);
		if (new->express->n >= value)
		{
			printf("Value found between indexes [%ld] and [%ld]\n",
				   new->index, new->express->index);
			break;
		}
		new = new->express;
	}

	if (new->express == NULL)
	{
		while (list->next != NULL)
			list = list->next;
		printf("Value found between indexes [%ld] and [%ld]\n",
			   new->index, list->index);
	}
	while (new != NULL)
	{
		printf("Value checked at index [%ld] = [%d]\n", new->index, new->n);
		if (new->n == value)
			return (new);
		new = new->next;
	}
	return (NULL);
}
