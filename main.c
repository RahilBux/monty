#include "monty.h"
carry_t carry = {NULL, NULL, NULL, 0};
/**
 * main - main code for monty
 * @argc: argument count
 * @argv: array of arguments
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char *str;
	FILE *file;
	stack_t *stack = NULL;
	unsigned int count = 0;
	ssize_t read = 1;
	size_t size = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	carry.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read > 0)
	{
		str = NULL;
		read = getline(&str, &size, file);
		carry.cont = str;
		count++;
		if (read > 0)
		{
			exec_func(str, &stack, count, file);
		}
		free(str);
	}
	free_s(stack);
	fclose(file);
	return (0);
}
