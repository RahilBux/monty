#include "monty.h"

/**
 * free_s - frees a stack
 * @head: head of stack
 */
void free_s(stack_t *head)
{
	stack_t *temp;

	temp = head;
	while (temp != NULL)
	{
		temp = temp->next;
		free(head);
		head = temp;
	}
}
