#include "monty.h"

/**
 * add_node - adds a node to the head
 * @head: head of list
 * @n: value to enter
 */

void add_node(stack_t **head, int n)
{
	stack_t *new, *temp;

	temp = *head;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (temp != NULL)
		temp->prev = new;
	new->n = n;
	new->next = temp;
	new->prev = NULL;
	*head = new;
}
