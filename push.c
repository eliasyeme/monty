#include "monty.h"

/**
 * push - pushe value to linked list.
 * @stack: stack_t linked list
 * @line_number: current line number of monty bytecode
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *new;
	int i;

	(void) line_number;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		op.err = 'm';
		last_to_err(err());
		return;
	}

	if (op.tokens[1] == NULL)
	{
		op.err = 'i';
		last_to_err(err());
		return;
	}

	for (i = 0; op.tokens[1][i]; i++)
	{
		if (op.tokens[1][i] == '-' && i == 0)
			continue;
		if (op.tokens[1][i] < '0' || op.tokens[1][i] > '9')
		{
			op.err = 'i';
			last_to_err(err());
			return;
		}
	}
	new->n = atoi(op.tokens[1]);

	if (check_mode(*stack) == 0) /* STACK mode insert at front */
	{
		tmp = (*stack)->next;
		new->prev = *stack;
		new->next = tmp;
		if (tmp)
			tmp->prev = new;
		(*stack)->next = new;
	}
	else /* QUEUE mode insert at end */
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		new->next = NULL;
		tmp->next = new;
	}
}
