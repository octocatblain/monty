#ifndef FILE_MONTY
#define FILE_MONTY
#define _GNU_SOURCE

/* imports */
#include <stdio.h>
#include <ctype.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/types.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct strct_s - struct of info's structs
 * @file: monty file
 * @line: line file
 * @stack: stack_t list
 * @line_number: line number
 * @state: int 0
 * Description: global struct with program info
 */
typedef struct strct_s
{
	FILE *file;
	char *line;
	stack_t *stack;
	unsigned int line_number;
	int state;
} strct_t;
extern strct_t strct;

/* prototypes */
int _isdigit(char *str);
void free_stck(stack_t *head);
strct_t free_collect(strct_t strct);
strct_t push(char *value, strct_t strct);
strct_t push1(char *value, strct_t strct);
void pall(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void lst_opcode(stack_t **stack, char *opcode, strct_t strct);

#endif
