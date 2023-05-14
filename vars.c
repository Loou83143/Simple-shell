#include "shell.h"

/**
 * is_chain - to  test if current character in buffer is a chain delimeter
 * @info: the parameter structure
 * @buf: the character buffer
 * @p: the address of current position in buffer
 *
 * Return: if chain delimeter 1, otherwise 0
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t j = *p;

	if (buf[c] == '|' && buf[c + 1] == '|')
	{
		buf[c] = 0;
		c++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[c] == '&' && buf[c + 1] == '&')
	{
		buf[c] = 0;
		c++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[c] == ';') /* found end of this command */
	{
		buf[c] = 0; /* replace semicolon with null */
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = c;
	return (1);
}

/**
 * check_chain - validates if  we should continue chaining based on last status
 * @info: parameter structure
 * @buf: the character buf
 * @p: the address of current position in buffer
 * @i: begining  position in buffer
 * @len: the length of buffer
 *
 * Return: Void
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			c = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[a] = 0;
			c = len;
		}
	}

	*p = c;
}

/**
 * replace_alias - stands inplace of an aliases in the tokenized string
 * @info: parameter structure
 *
 * Return: if replaced 1, otherwise 0
 */
int replace_alias(info_t *info)
{
	int i;
	list_t *node;
	char *p;

	for (a = 0; a < 10; a++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}

/**
 * replace_vars - stands in place of vars in the tokenized string
 * @info: parameter structure
 *
 * Return: if replaced 1, otherwise 0
 */
int replace_vars(info_t *info)
{
	int a = 0;
	list_t *node;

	for (a = 0; info->argv[a]; a++)
	{
		if (info->argv[a][0] != '$' || !info->argv[a][1])
			continue;

		if (!_strcmp(info->argv[a], "$?"))
		{
			replace_string(&(info->argv[a]),
				_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[a], "$$"))
		{
			replace_string(&(info->argv[a]),
				_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[a][1], '=');
		if (node)
		{
			replace_string(&(info->argv[i]),
				_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[a], _strdup(""));

	}
	return (0);
}

/**
 * replace_string - stands in place of string
 * @old: The address of old string
 * @new: The new string
 *
 * Return: if replaced 1, otherwise 0
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
