#include "monty.h"

/**
 * func_pchar - prints the ascii value at the top of stack
 * @head: pointer to head of stack
 * @count: line counter
 */
void func_pchar(stack_t **head, unsigned int count)
{
	stack_t *p1;
	int len = 0;
	
	p1 = *head;
	while (p1 != NULL)
	{
		p1 = p1->next;
		len++;
	}
	if (len <= 0)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", count);
		fclose(carry.file);
		free(carry.cont);
		free_s(*head);
		exit(EXIT_FAILURE);
	}
	p1 = *head;
	if (p1->n > 127 || p1->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", count);
		fclose(carry.file);
		free(carry.cont);
		free_s(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", p1->n);
}
