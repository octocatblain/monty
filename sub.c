#include "monty.h"

/**
 * sub - sub
 * @stack: head stack
 * @line_number: line number
 * Return: (void)
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	stack_t *next;

	if (!current || !current->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	next = current->next;
	next->n -= current->n;
	pop(stack, line_number);
}
