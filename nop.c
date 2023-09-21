#include "monty.h"

/**
 * nop - does nothing
 * @stack: stack_t linked list
 * @line_number: current line number of monty bytecode
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
