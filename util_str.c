#include "monty.h"

/**
 * tokenize - get words array from a string
 * @str: string to proccess
 *
 * Return:  NULL on fail
 *					string array otherwise
 */
char **tokenize(char *str)
{
	char **words = NULL;
	int wc, wordLen, n, i = 0;

	if (str == NULL || !*str)
		return (NULL);
	wc = word_count(str);

	if (wc == 0)
		return (NULL);
	words = malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	while (i < wc)
	{
		wordLen = word_len(str);
		if (isspace(*str))
			str = next_word(str);

		words[i] = malloc((wordLen + 1) * sizeof(char));
		if (words[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(words[i]);
			}
			free(words);
			return (NULL);
		}
		n = 0;
		while (n < wordLen)
		{
			words[i][n] = *(str + n);
			n++;
		}
		words[i][n] = '\0'; /* set end of str */
		str = next_word(str);
		i++;
	}
	words[i] = NULL; /* last element is null for iteration */
	return (words);
}

/**
 * word_len - gets the word length of cur word in str
 * @str: string to get word length from current word
 *
 * Return: word length of current word
 */
int word_len(const char *str)
{
	int len = 0, state = 1;

	while (*str)
	{
		if (isspace(*str))
			state = 1;
		else if (state)
		{
			len++;
		}
		if (len && isspace(*str))
			break;
		str++;
	}
	return (len);
}

/**
 * word_count - gets the word count of a string
 * @str: string to get word count from
 *
 * Return: the word count of the string
 */
int word_count(const char *str)
{
	int wc = 0, state = 1;

	while (*str)
	{
		if (isspace(*str))
			state = 1;
		else if (state)
		{
			state = 0;
			wc++;
		}
		str++;
	}
	return (wc);
}

/**
 * next_word - gets the next word in a string
 *
 * @str: string to get next word from
 * @delims: delimitors to use to delimit words
 *
 * Return: pointer to first char of next word
 */
char *next_word(char *str)
{
	int state = 0;

	while (*str)
	{
		if (isspace(*str))
			state = 1;
		else if (state)
			break;
		str++;
	}
	return (str);
}
