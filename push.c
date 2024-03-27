#include "monty.h"

/**
 * func_push - adds node to the stack
 * @head: head of stack
 * @count: line number
 */
void func_push(stack_t **head, unsigned int count)
{
	int i, j = 0, f = 0;

	if (carry.args)
	{
		if (carry.args[0] == '-')
			j++;
		for (; carry.args[j] != '\0'; j++)
		{
			if (carry.args[j] > 57 || carry.args[j] < 48)
				f = 1;
		}
		if (f == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", count);
			fclose(carry.file);
			free(carry.str);
			free_s(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", count);
		fclose(carry.file);
		free(carry.str);
		free_s(*head);
		exit(EXIT_FAILURE);
	}
	i = atoi(carry.args);
	add_node(head, i);
}
