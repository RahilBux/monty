#include "monty.h"

/**
 * func_swap - swaps the top 2 elements of the stack
 * @head: head of the stack
 * @count: line count
 */
void func_swap(stack_t **head, unsigned int count)
{
	stack_t *p1;
	int len = 0, temp;

	p1 = *head;
	while (p1 != NULL)
	{
		p1 = p1->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", count);
		fclose(carry.file);
		free(carry.cont);
		free_s(*head);
		exit(EXIT_FAILURE);
	}
	p1 = *head;
	temp = p1->n;
	p1->n = p1->next->n;
	p1->next->n = temp;
}
