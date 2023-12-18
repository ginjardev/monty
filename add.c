#include "monty.h"

/**
 * add_fxn - Adds the top two elements of the stack or queue.
 * @head: head pointer to stack or queue.
 * @lnum: Is the current line.
 */
void add_fxn(stack_t **head, unsigned int lnum)
{
	stack_t *ult, *penult;

	if ((*head)->next == NULL || *head == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", lnum);
		exit(EXIT_FAILURE);
	}

	ult = *head;
	penult = ult->next;

	(penult->n) += (ult->n);

	*head = penult;
	penult->prev = NULL;
	free(ult);
}
