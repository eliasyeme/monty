#include "monty.h"

/**
 * err - handle errors
 * Return: error code
 */
int err(void)
{
	char str[124];

	switch (op.err)
	{
	case 'u':
		sprintf(str, "USAGE: monty file\n");
		break;
	case 'f':
		sprintf(str, "Error: Can't open file %s\n", op.filename);
		break;
	case 'm':
		sprintf(str, "Error: malloc failed\n");
		break;
	case 'i':
		sprintf(str, "L%u: unknown instruction %s\n", op.line_number, op.tokens[0]);
		break;
	case 'p':
		sprintf(str, "L%u: usage: push integer\n", op.line_number);
		break;
	case 'o':
		sprintf(str, "L%u: can't pop an empty stack\n", op.line_number);
		break;
	case 't':
		sprintf(str, "L%d: can't pint, stack empty\n", op.line_number);
		break;
	case 's':
		sprintf(str, "L%u: can't %s, stack too short\n",
					op.line_number, op.tokens[0]);
		break;
	default:
		return (EXIT_SUCCESS);
	}
	fprintf(stderr, "%s", str);
	return (EXIT_FAILURE);
}


/**
 * last_to_err - Sets last element of tokens to be an error code.
 * @error_code: Integer to store as a string in tokens.
 */
void last_to_err(int error_code)
{
	int toks_len = 0, i = 0;
	char exit_str[2];
	char **new_toks = NULL;

	toks_len = token_arr_len();
	new_toks = malloc(sizeof(char *) * (toks_len + 2));
	if (!op.tokens)
	{
		op.err = 'm';
		err();
		return;
	}
	while (i < toks_len)
	{
		new_toks[i] = op.tokens[i];
		i++;
	}

	sprintf(exit_str, "%d", error_code);
	if (!*exit_str)
	{
		free(new_toks);
		op.err = 'm';
		err();
		return;
	}
	new_toks[i++] = exit_str;
	new_toks[i] = NULL;
	free(op.tokens);
	op.tokens = new_toks;
}
