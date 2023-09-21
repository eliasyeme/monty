#include "monty.h"

/**
 * swap - swaps top two values
 * @stack: stack_t linked list
 * @line_number: current line number of monty bytecode
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		op.err = 's';
		last_to_err(err());
		return;
	}

	tmp = (*stack)->next->next;
	(*stack)->next->next = tmp->next;
	(*stack)->next->prev = tmp;
	if (tmp->next)
		tmp->next->prev = (*stack)->next;
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;
}
