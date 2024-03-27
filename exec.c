#include "monty.h"

/**
 * exec_func - executes the opcode
 * @stack: head of stack
 * @count: line count
 * @file: file containing monty code
 * @str: string of contents
 *
 * Return: 1 or 0
 */
int exec_func(char *str, stack_t **stack, unsigned int count, FILE *file)
{
	instruction_t opfunc[] = {
		{"push", func_push},
		{"pall", func_pall},
		{"pint", func_pint},
		{"pop", func_pop},
		{"swap", func_swap},
		{"add", func_add},
		{"nop", func_nop},
		{"sub", func_sub},
		{"div", func_div},
		{"mul", func_mul},
		{NULL, NULL}
	};

	unsigned int i = 0;
	char *op;

	op = strtok(str, " \n\t");
	if (op && op[0] == '#')
		return (0);
	carry.args = strtok(NULL, " \n\t");
	while (opfunc[i].opcode && op)
	{
		if (strcmp(op, opfunc[i].opcode) == 0)
		{
			opfunc[i].f(stack, count);
			return (0);
		}
		i++;
	}
	if (op && opfunc[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", count, op);
		fclose(file);
		free(str);
		free_s(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
