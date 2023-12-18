#include "monty.h"
/**
 * pint_fxn - prints value in head pointer
 * @head: head pointer
 * @lnum: is current line number
 */
void pint_fxn(stack_t **head, unsigned int lnum)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint_fxn, stack empty\n", lnum);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}
