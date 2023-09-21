#include "monty.h"

/**
 * pall - Prints the values of a stack_t linked list.
 * @stack: stack_t linked list
 * @line_number: current line number of monty bytecode
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	(void)line_number;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
