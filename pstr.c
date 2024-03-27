#include "monty.h"

/**
 * func_pstr - prints a string starting at the top of stack
 * @head: head of stack
 * @count: line count
 */
void func_pstr(stack_t **head, unsigned int count)
{
	(void)count;
	stack_t *p1 = *head;

	while (p1 != NULL)
	{
		if (p1->n <= 0 || p1->n > 127)
			break;
		printf("%c", p1->n);
		p1 = p1->next;
	}
	printf("\n");
}
