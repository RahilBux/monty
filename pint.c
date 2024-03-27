#include "monty.h"

/**
 * func_pint - prints the top of stack
 * @head: stack head
 * @counter: line count
 */
void func_pint(stack_t **head, unsigned int counter)
{
	stack_t *p1 = *head;
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(carry.file);
		free(carry.cont);
		free_s(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", p1->n);
}
