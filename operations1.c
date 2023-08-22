#include "monty.h"

/**
 * swap - swap two elements
 * @stack: head of stack
 * @line_number: line number
 * Return: (void)
 */
void swap(stack_t **stack, unsigned int line_number)
{
	register int tmp;
	stack_t *current = *stack;
	stack_t *next;

	if (!current || !current->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	next = current->next;
	tmp = current->n;
	current->n = next->n;
	next->n = tmp;
}
