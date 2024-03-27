#include "monty.h"

/**
 * func_mod - computes the remainder of the top 2 elements of the stack
 * @head: head of the stack
 * @count: line counter
 */
void func_mod(stack_t **head, unsigned int count)
{
	stack_t *p1;
	int result, len = 0;

	p1 = *head;
	while (p1 != NULL)
	{
		p1 = p1->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", count);
		fclose(carry.file);
		free(carry.cont);
		free_s(*head);
		exit(EXIT_FAILURE);
	}
	p1 = *head;
	if (p1->n == 0)
	{
		fprintf(stderr, "L%d, division by zero\n", count);
		fclose(carry.file);
		free(carry.cont);
		free_s(*head);
		exit(EXIT_FAILURE);
	}
	result = p1->next->n % p1->n;
	p1->next->n = result;
	*head = p1->next;
	free(p1);
}
