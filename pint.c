#include "monty.h"

/**
 * pint - print first node
 * @stack: head stack
 * @line_number: line number
 * Return: (void)
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (!current)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", current->n);
}
