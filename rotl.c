#include "monty.h"

/**
 * func_rotl - rotates the top to the bottom
 * @head: head of stack
 * @count: line counter
 */
void func_rotl(stack_t **head, unsigned int count)
{
	stack_t *p1, *p2;
	(void)count;

	if (*head == NULL || (*head)->next == NULL)
		return;

	p1 = *head;
	p2 = *head;
	while (p1->next != NULL)
	{
		p1 = p1->next;
	}
	p1->next = p2;
	*head = p2->next;
	p2->next = NULL;
	p2->prev = p1;
	(*head)->prev = NULL;
}
