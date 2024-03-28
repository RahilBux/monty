#include "monty.h"

/**
 * func_rotr - rotate the stack
 * @head: head of stack
 * @count: line count
 */
void func_rotr(stack_t **head, unsigned int count)
{
	stack_t *p1;
	(void)count;

	p1 = *head;
	if (*head == NULL || (*head)->next == NULL)
		return;

	while (p1->next != NULL)
		p1 = p1->next;
	p1->next = *head;
	p1->prev->next = NULL;
	p1->prev = NULL;
	(*head)->prev = p1;
	*head = p1;
}
