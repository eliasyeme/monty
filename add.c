#include "monty.h"

/**
 * add - Adds the top two values of a stack_t linked list
 * @stack: stack_t linked list
 * @line_number: current line number of monty bytecode
 */
void add(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		op.err = 's';
		last_to_err(err());
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	pop(stack, line_number);
}
