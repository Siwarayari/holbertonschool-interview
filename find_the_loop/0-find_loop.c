#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"
/**
 * find_listint_loop - function that finds the loop in a linked list.
 * @head: the head of the listable list
 * Return: Null or fast.
*/
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow = head;
	listint_t *fast = head;

	if (head == NULL)
		return (NULL);

	slow = slow->next;
	fast = fast->next->next;

	while (fast->next && fast->next->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			break;
	}
	if (slow != fast)
	{
		return (NULL);
	}

	fast = head;
	while (fast != slow)
	{
		slow = slow->next;
		fast = fast->next;
	}

		return (fast);
	return (NULL);
}
