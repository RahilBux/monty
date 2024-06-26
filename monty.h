#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct carry_s - variables
 * @args: value
 * @file: pointer to file
 * @cont: content
 * @change: changes stack <-> queue
 *
 * Description: carries values to functions
 */
typedef struct carry_s
{
	char *args;
	FILE *file;
	char *cont;
	int change;
} carry_t;
extern carry_t carry;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void func_push(stack_t **head, unsigned int count);
int exec_func(char *str, stack_t **stack, unsigned int count, FILE *file);
void func_pall(stack_t **head, unsigned int count);
void free_s(stack_t *head);
void add_node(stack_t **head, int n);
void func_pint(stack_t **head, unsigned int count);
void func_pop(stack_t **head, unsigned int count);
void func_swap(stack_t **head, unsigned int count);
void func_add(stack_t **head, unsigned int count);
void func_nop(stack_t **head, unsigned int count);
void func_sub(stack_t **head, unsigned int count);
void func_div(stack_t **head, unsigned int count);
void func_mul(stack_t **head, unsigned int count);
void func_mod(stack_t **head, unsigned int count);
void func_pchar(stack_t **head, unsigned int count);
void func_pstr(stack_t **head, unsigned int count);
void func_rotl(stack_t **head, unsigned int count);
void func_rotr(stack_t **head, unsigned int count);

#endif
