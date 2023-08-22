#include "monty.h"

/**
 * lst_opcode - List opcode
 * inst_tble: instructions
 * @stack: stack_t
 * @strct: strct_t
 * @opcode: data line
 */
void lst_opcode(stack_t **stack, char *opcode, strct_t strct)
{
	register int i;
	char *opc;
	instruction_t inst_tble[] = {
/*
 *{"push", },
 *{"sub", },
 *{"div", },
 *{"mul", },
 *{"mod", },
 *{"pchar", },
 *{"pstr", },
 *{"rotl", },
 *{"rotr", },
 */
{"add", add},
{"sub", sub},
{"pint", pint},
{"pop", pop},
{"swap", swap},
{"nop", nop},
{"pall", pall},
{NULL, NULL}
};

	opc = strtok(opcode, "\n");
	for (i = 0; inst_tble[i].opcode; i++)
		if (strcmp(opc, inst_tble[i].opcode) == 0)
		{
			inst_tble[i].f(stack, strct.line_number);
			return;
		}

	dprintf(STDERR_FILENO, "L%d: ", strct.line_number);
	dprintf(STDERR_FILENO, "unknown instruction %s\n", opcode);
	fclose(strct.file);
	free(strct.line);
	free_stck(strct.stack);
	exit(EXIT_FAILURE);
}
