#include "monty.h"

/**
 * func_pall - prints all elements in the stack
 * @head: head of stack
 * @count: line counter
 */
void func_pall(stack_t **head, unsigned int count)
{
	stack_t *p1;
	(void)count;

	p1 = *head;
	if (p1 == NULL)
		return;
	while (p1 != NULL)
	{
		printf("%d\n", p1->n);
		p1 = p1->next;
	}
}
