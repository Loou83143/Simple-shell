#include "shell.h"

/**
 * **strtow - separate a string into words. repeat delimiters are ignored
 * @str: The input string
 * @d: delimeter string
 * Return: points to an array of strings, or NULL on failure
 */

char **strtow(char *str, char *d)
{
	int a, c, l, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (a = 0; str[a] != '\0'; a++)
		if (!is_delim(str[a], d) && (is_delim(str[a + 1], d) || !str[a + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (a = 0, c = 0; c < numwords; c++)
	{
		while (is_delim(str[a], d))
			a++;
		l = 0;
		while (!is_delim(str[a + l], d) && str[a + l])
			l++;
		s[c] = malloc((l + 1) * sizeof(char));
		if (!s[c])
		{
			for (l = 0; l < c; l++)
				free(s[l]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < l; m++)
			s[c][m] = str[a++];
		s[c][m] = 0;
	}
	s[c] = NULL;
	return (s);
}

/**
 * **strtow2 - separate a string into words
 * @str: input string
 * @d: delimeter
 * Return:  points to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
	int a, c, l, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (a = 0; str[a] != '\0'; a++)
		if ((str[a] != d && str[a + 1] == d) ||
		    (str[a] != d && !str[a + 1]) || str[a + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (a = 0, c = 0; c < numwords; c++)
	{
		while (str[a] == d && str[a] != d)
			a++;
		l = 0;
		while (str[a + l] != d && str[a + l] && str[a + l] != d)
			l++;
		s[c] = malloc((l + 1) * sizeof(char));
		if (!s[c])
		{
			for (l = 0; l < c; l++)
				free(s[c]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < l; m++)
			s[c][m] = str[a++];
		s[c][m] = 0;
	}
	s[c] = NULL;
	return (s);
}
