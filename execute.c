#include "monty.h"

/**
 * run - executes an opcode operation.
 * @opcode: opcode name to be run.
 * @elem: The argument associated with the opcode (if applicable).
 * @head: double pointer to stack.
 * @n: the line number corresponding to the opcode in the program.
 */
void run(char *opcode, char *elem, stack_t **head, unsigned int n)
{
	int i = 0;
	instruction_t codes_arr[] = {
		{"pall", pall_fxn}, {"pint", pint_fxn},
		{"pop", pop_fxn}, {"add", add_fxn},
		{"nop", nop_fxn}, {"swap", swap_fxn},
		{"sub", sub_fxn}, {"div", div_fxn},
		{"mul", mul_fxn}, {"mod", mod_fxn},
		{"pstr", pstr_fxn}, {"rotl", rotl_fxn},
		{"stack", stack_fxn}, {"queue", queue_fxn},
		{"rotr", rotr_fxn}, {"pchar", pchar_fxn},
		{NULL, NULL}
	};

	if (strcmp(opcode, "push") == 0)
	{
		if (strlen(elem) == 0 || elem == NULL || !_isdigit(elem))
		{
			fprintf(stderr, "L%u: usage: push integer\n", n);
			exit(EXIT_FAILURE);
		}
		else
		{
		push_fxn(head, n, atoi(elem));
		return;
		}
	}

	for (i = 0; codes_arr[i].opcode != NULL; i++)
	{
		if (strcmp(codes_arr[i].opcode, opcode) == 0)
		{
			codes_arr[i].f(head, n);
			return;
		}
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", n, opcode);
	exit(EXIT_FAILURE);
}
