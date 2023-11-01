#include <stdlib.h>
#include "main.h"

/**
 * argstostr - concatenates all the arguments of the program
 * @ac: number of arguments
 * @av: array of arguments
 * Return: pointer to a new string containing concatenated arguments
 * or NULL if it fails
 */
char *argstostr(int ac, char **av)
{
	char *str;
	int i, j, len = 0, total_len = 0;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
		{
			len++;
		}
		total_len += len + 1; /* Add 1 for newline character */
		len = 0;
	}

	str = malloc(sizeof(char) * total_len + 1); /* Add 1 for null terminator */
	if (str == NULL)
		return (NULL);

	len = 0;
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
		{
			str[len] = av[i][j];
			len++;
		}
		str[len] = '\n'; /* Add newline character */
		len++;
	}

	str[len] = '\0'; /* Null-terminate the string */
	return (str);
}
