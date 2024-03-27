#include "monty.h"

/**
 * func_pop - removes the top of stack
 * @head: head of stack
 * @count: line count
 */
void func_pop(stack_t **head, unsigned int count)
{
	stack_t *p1;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		fclose(carry.file);
		free(carry.cont);
		free_s(*head);
		exit(EXIT_FAILURE);
	}
	p1 = *head;
	*head = p1->next;
	free(p1);
}
