#include "shell.h"

/**
 * bfree - Nulls the address and frees the pointer
 * @ptr: the pointer address to be freed
 *
 * Return:if freed 1, 0 otherwise
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
