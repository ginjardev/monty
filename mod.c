#include "monty.h"

/**
 * mod_fxn - gets the remainder after division of the the last (ultimate)
 * by the second last (penultimate) element.
 * @head: pointer to head node.
 * @lnum: The current line number being executed.
 */
void mod_fxn(stack_t **head, unsigned int lnum)
{
	stack_t *ult, *penult;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod_fxn, stack too short\n", lnum);
		exit(EXIT_FAILURE);
	}

	ult = *head;
	penult = ult->next;

	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", lnum);
		exit(EXIT_FAILURE);
	}

	penult->n = penult->n % ult->n;

	*head = penult;
	penult->prev = NULL;
	free(ult);
}
