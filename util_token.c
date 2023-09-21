#include "monty.h"

/**
 * is_empty - check if a string is whitespace
 * @s: string to check
 *
 * Return: 1 is empty 0 otherwise
 */
int is_empty(const char *s)
{
	while (*s)
	{
		if (!isspace((unsigned char)*s))
			return (1);
		s++;
	}
	return (0);
}

/**
 * free_tokens - Frees the global tokens array of strings.
 */
void free_tokens(void)
{
	size_t i = 0;

	if (op.tokens == NULL)
		return;

	for (i = 0; op.tokens[i]; i++)
		free(op.tokens[i]);

	free(op.tokens);
}

/**
 * token_arr_len - Gets the length of current tokens.
 *
 * Return: Length of current tokens (as int).
 */
unsigned int token_arr_len(void)
{
	unsigned int toks_len = 0;

	while (op.tokens[toks_len])
		toks_len++;
	return (toks_len);
}
