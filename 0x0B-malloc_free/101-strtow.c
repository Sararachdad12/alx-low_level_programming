#include <stdlib.h>
#include "main.h"

/**
 * count_words - Count the number of words in a string.
 * @str: Input string.
 * Return: Number of words.
 */
int count_words(char *str)
{
	int count = 0;
	int in_word = 0;

	while (*str)
	{
		if (*str == ' ')
		{
			in_word = 0;
		}
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}

		str++;
	}

	return (count);
}

/**
 * strtow - Splits a string into words.
 * @str: Input string.
 * Return: Pointer to an array of strings (words).
 */
char **strtow(char *str)
{
	if (str == NULL || *str == '\0')
		return (NULL);

	int i, j, len = 0, word_count = count_words(str);
	char **words = malloc(sizeof(char *) * (word_count + 1));

	if (words == NULL)
		return (NULL);

	for (i = 0; i < word_count; i++)
	{
		while (*str == ' ')
			str++;

		for (len = 0; str[len] != ' ' && str[len] != '\0'; len++)
			;

		words[i] = malloc(sizeof(char) * (len + 1));

		if (words[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(words[j]);
			free(words);
			return (NULL);
		}

		for (j = 0; j < len; j++)
			words[i][j] = *str++;

		words[i][len] = '\0';
	}

	words[i] = NULL;
	return (words);
}
