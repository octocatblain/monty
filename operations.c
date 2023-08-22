#include "monty.h"

/**
 * push - add node in stack_t
 * @value: value's node
 * @strct: strct_t
 * Return: (strct)
 */
strct_t push(char *value, strct_t strct)
{
	register int n;
	stack_t *new, *current = strct.stack;
	char *ptr = NULL;

	ptr = strchr(value, '\n');
	if (ptr)
		*ptr = 0;
	if (!strlen(value) || !_isdigit(value))
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", strct.line_number);
		fclose(strct.file);
		free(strct.line);
		free_stck(strct.stack);
		exit(EXIT_FAILURE);
	}
	n = atoi(value);
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		fclose(strct.file);
		free(strct.line);
		free_stck(strct.stack);
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = NULL;
	if (!current)
	{
		new->prev = NULL;
		strct.stack = new;
		return (strct);
	}
	while (current->next)
	{
		current = current->next;
	}
	current->next = new;
	new->prev = current;
	return (strct);
}

/**
 * push1 - add node in stack_t
 * @value: value's node
 * @strct: strct_t
 * Return: strct_t
 */
strct_t push1(char *value, strct_t strct)
{
	register int n;
	stack_t *new;
	char *ptr = NULL;

	ptr = strchr(value, '\n');
	if (ptr)
		*ptr = 0;
	if (!strlen(value) || !_isdigit(value))
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", strct.line_number);
		fclose(strct.file);
		free(strct.line);
		free_stck(strct.stack);
		exit(EXIT_FAILURE);
	}
	n = atoi(value);
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		fclose(strct.file);
		free(strct.line);
		free_stck(strct.stack);
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = strct.stack;
	new->prev = NULL;
	if (new->next)
		new->next->prev = new;
	strct.stack = new;
	return (strct);
}

/**
 * pall - print all stack_t
 * @stack: head stack
 * @line_number: line number
 * Return: (void)
 */
void pall(stack_t **stack, unsigned int line_number)
{
	unsigned int i = 0;
	stack_t *current = *stack;

	(void)line_number;

	if (current == NULL)
	{
		return;
	}
	/*
	 * while (current->next)
	 * {
	 *	current = current->next;
	 * }
	 * while (current)
	 * {
	 *	printf("%d\n", current->n);
	 *	current = current->prev;
	 * }
	 */
	for (i = 0; current; i++, current = current->next)
	{
		printf("%d\n", current->n);
	}

}
