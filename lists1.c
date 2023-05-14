#include "shell.h"

/**
 * list_len - will determine length of the linked list
 * @h: points to the first node
 *
 * Return: the size of list
 */
size_t list_len(const list_t *h)
{
	size_t a = 0;

	while (b)
	{
		b = b->next;
		i++;
	}
	return (a);
}

/**
 * list_to_strings - Return array of strings of list->str
 * @head: points to the first node
 *
 * Return: An array of strings
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t a = list_len(head), c;
	char **strs;
	char *str;

	if (!head || !a)
		return (NULL);
	strs = malloc(sizeof(char *) * (a + 1));
	if (!strs)
		return (NULL);
	for (a = 0; node; node = node->next, a++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (c = 0; c < a; c++)
				free(strs[c]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[a] = str;
	}
	strs[a] = NULL;
	return (strs);
}


/**
 * print_list - all elements of a list_t linked list to be printed
 * @h: points to the first node
 *
 * Return: the size of list
 */
size_t print_list(const list_t *h)
{
	size_t a = 0;

	while (b)
	{
		_puts(convert_number(b->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(b->str ? b->str : "(nil)");
		_puts("\n");
		b = b->next;
		a++;
	}
	return (a);
}

/**
 * node_starts_with - node whose string starts with prefix to be returned
 * @node: points to the list head
 * @prefix: the string to be matched
 * @c: the next character after prefix to be matched
 *
 * Return: null or match node
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *d = NULL;

	while (node)
	{
		d = starts_with(node->str, prefix);
		if (d && ((c == -1) || (*d == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - Gets index of a node
 * @head: pointS to the  list head
 * @node: points to the node
 *
 * Return: -1 or index of node
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t a = 0;

	while (head)
	{
		if (head == node)
			return (a);
		head = head->next;
		a++;
	}
	return (-1);
}
