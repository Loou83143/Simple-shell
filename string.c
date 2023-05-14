#include "shell.h"

/**
 * _strlen - Returns the length of a string
 * @s: the string whose length to be checked
 *
 * Return: int length of the string
 */
int _strlen(char *s)
{
	int a = 0;

	if (!s)
		return (0);

	while (*s++)
		a++;
	return (a);
}

/**
 * _strcmp - performs lexi-cogarphic comparison of two the strangs.
 * @s1: First strang
 * @s2: Second strang
 *
 * Return: positive if s1 > s2, negative if s1 < s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - to check if needle starts with haystack
 * @haystack: string to be searched
 * @needle: the substring to be found
 *
 * Return: the address of next character of NULL or haystack
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - links two strings
 * @dest: the terminus  buffer
 * @src: source buffer
 *
 * Return: points to terminus buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
