#include "monty.h"

/**
 * pint - Prints the top value of a stack_t linked list.
 * @stack: stack_t linked list
 * @line_number: current line number of monty bytecode
 */
void pint(stack_t **stack, unsigned int line_number)
{
	(void) line_number;

	if ((*stack)->next == NULL)
	{
		op.err = 't';
		last_to_err(err());
		return;
	}

	printf("%d\n", (*stack)->next->n);
}
