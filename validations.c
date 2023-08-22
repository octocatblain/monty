#include "monty.h"

/**
 * free_collect - handle free
 * @strct: strct_t strct
 * Return: (strct)
 */
strct_t free_collect(strct_t strct)
{
	fclose(strct.file);
	if (strct.line)
	{
		free(strct.line);
		strct.line = NULL;
	}
	if (strct.stack)
	{
		free_stck(strct.stack);
		strct.stack =  NULL;
	}
	return (strct);
}

/**
 * free_stck - free stack_t
 * @head: pointer head stack
 * Return: (void)
 */
void free_stck(stack_t *head)
{
	stack_t *tmp, *current = head;

	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
}

/**
 * _isdigit - is digit
 * @str: string
 * Return: true or false
 */
int _isdigit(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] == '-')
		{
			i++;
			continue;
		}
		else if (!isdigit(str[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
