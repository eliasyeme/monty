#include "monty.h"

/**
 * pop - Removes the top value element of a stack_t linked list.
 * @stack: stack_t linked list
 * @line_number: current line number of monty bytecode
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next = NULL;

	(void) line_number;
	if ((*stack)->next == NULL)
	{
		op.err = 'o';
		last_to_err(err());
		return;
	}

	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}
