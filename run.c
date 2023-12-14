#include "monty.h"
/**
* run - executes the opcode
* @stack: head linked list - stack
* @linecnt: line_counter
* @file: poiner to monty file
* @streamptr: pointer to stream content
* Return: no return
*/
int run(char *streamptr, stack_t **stack, unsigned int linecnt, FILE *file)
{
	instruction_t opst[] = {
				{"push", push_fxn},
				{"pall", pall_fxn},
				{"pint", pint_fxn},
				{"pop", pop_fxn},
				{"swap", swap_fxn},
				{"add", add_fxn},
				{"nop", nop_fxn},
				{NULL, NULL}
				};
	unsigned int k = 0;
	char *opr;

	opr = strtok(streamptr, " \n\t");
	if (opr && opr[0] == '#')
		return (0);

	while (opst[k].opcode && opr)
	{
		if (strcmp(opr, opst[k].opcode) == 0)
		{	opst[k].f(stack, linecnt);
			return (0);
		}
		k++;
	}
	if (opr && opst[k].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", linecnt, opr);
		fclose(file);
		free(streamptr);
		freestk(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
