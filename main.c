#include "monty.h"

/**
 * refractor - to initialize in empty data
 * @strct: global variable
 * Return: (strct)
 */
strct_t refractor(strct_t strct)
{
	strct.file = NULL;
	strct.line = NULL;
	strct.stack = NULL;
	strct.line_number = 1;
	strct.state = 0;
	return (strct);
}

/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: Pointer to arguments array
 * Return: 0 on success or 1 on error
 */
int main(int argc, char **argv)
{
	strct_t strct;
	char *opcode, *val;
	ssize_t read = 0;
	size_t len = 0;

	strct = refractor(strct);
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	strct.file = fopen(argv[1], "r");
	if (!strct.file)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&strct.line, &len, strct.file)) != -1)
	{
		opcode = strtok(strct.line, " \t");
		if (*opcode == '#' || *opcode == '\n')
		{
			strct.line_number++;
			continue;
		}
		if (strcmp(opcode, "push") == 0)
		{
			val = strtok(NULL, " ");
			strct = push1(val, strct);
			strct.line_number++;
			continue;
		}
		lst_opcode(&strct.stack, opcode, strct);
		strct.line_number++;
	}
	free_collect(strct);
	return (0);
}
