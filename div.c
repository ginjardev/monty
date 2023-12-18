#include "monty.h"
/**
 * div_fxn - divides the last (ultimate) by the
 * second last (penultimate) element.
 * @head: pointer to head node.
 * @lnum: The line number.
 */
void div_fxn(stack_t **head, unsigned int lnum)
{
	stack_t *ult, *penult;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", lnum);
		exit(EXIT_FAILURE);
	}
	else if ((*head)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", lnum);
		exit(EXIT_FAILURE);
	}

	ult = *head;
	penult = ult->next;

	penult->n /= ult->n;

	*head = penult;
	penult->prev = NULL;
	free(ult);
}
