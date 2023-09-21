#define  _GNU_SOURCE
#include "monty.h"

/* err, filename, file, lineptrnumber */
op_t op = {0, NULL, NULL, NULL, 0};

/**
 * main - monty interpreter
 * @ac: argument count
 * @av: argument value
 *
 * Return:  0 on success
 *					1 on fail
 */
int main(int ac, char **av)
{
	int exit_status;

	if (ac != 2)
	{
		op.err = 'u';
		return (err());
	}
	op.filename = av[1];
	op.file = fopen(op.filename, "r");

	if (op.file == NULL)
	{
		op.err = 'f';
		return (err());
	}

	exit_status = exec();
	fclose(op.file);

	return (exit_status);
}

/**
 * exec - execute commands from monty file
 *
 * Return: status code
 */
int exec(void)
{
	stack_t *stack = NULL;
	char *lineptr = NULL;
	size_t n = 0, exit_status = EXIT_SUCCESS;

	if (init_stack(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&lineptr, &n, op.file) != -1)
	{
		op.line_number++;
		op.tokens = tokenize(lineptr);
		if (op.tokens == NULL)
		{
			if (is_empty(lineptr))
				continue;
			free_stack(&stack);
			op.err = 'm';
			return (err());
		}
		else if (op.tokens[0][0] == '#') /* comment lineptr */
		{
			free_tokens();
			continue;
		}

		if (call_func(&stack))
			break;

		free_tokens();
	}
	free_stack(&stack);

	if (lineptr && *lineptr == 0)
	{
		free(lineptr);
		op.err = 'm';
		return (err());
	}
	free(lineptr);
	return (exit_status);
}

/**
 * get_opfunc - Matches an opcode with its corresponding function.
 *
 * Return: A pointer to the corresponding function.
 */
void (*get_opfunc())(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	int i;
	char *opcode = op.tokens[0];

	for (i = 0; op_funcs[i].opcode; i++)
	{
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
			return (op_funcs[i].f);
	}

	return (NULL);
}

/**
 * call_func - call the actual monty function
 * @stack: code source
 *
 * Return: status code
 */
int call_func(stack_t **stack)
{
	size_t exit_status = EXIT_SUCCESS;
	void (*op_func)(stack_t**, unsigned int);
	unsigned int len = 0;

	op_func = get_opfunc();
	if (op_func == NULL)
	{
		free_stack(stack);
		op.err = 'i';
		exit_status = err();
		free_tokens();
		return (exit_status);
	}
	len = token_arr_len();
	op_func(stack, op.line_number);
	if (token_arr_len() != len)
	{
		if (op.tokens && op.tokens[len])
			exit_status = atoi(op.tokens[len]);
		else
			exit_status = EXIT_FAILURE;
		free_tokens();
		return (exit_status);
	}
	return (exit_status);
}
