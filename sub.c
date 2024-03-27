#include "monty.h"

/**
 * func_sub - subtract the top 2 elements of the stack
 * @head: head of the stack
 * @count: line counter
 */
void func_sub(stack_t **head, unsigned int count)
{
	stack_t *p1;
	int len = 0, result;

	p1 = *head;
	while (p1 != NULL)
	{
		p1 = p1->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", count);
		fclose(carry.file);
		free(carry.cont);
		free_s(*head);
		exit(EXIT_FAILURE);
	}
	p1 = *head;
	result = p1->next->n - p1->n;
	p1->next->n = result;
	*head = p1->next;
	free(p1);
}
