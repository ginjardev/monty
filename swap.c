#include "monty.h"

/**
 * swap_fxn - swaps the last two elements.
 * @head: Head pointer.
 * @lnum: Current line number.
 */
void swap_fxn(stack_t **head, unsigned int lnum)
{
	int tmp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", lnum);
		exit(EXIT_FAILURE);
	}

	tmp = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = tmp;
}
