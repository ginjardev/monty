#include "monty.h"
/**
 * mul_fxn - multiplies the the last (ultimate) by the
 * second last (penultimate) element.
 * @head: pointer to head node.
 * @lnum: The current line number being executed.
 */
void mul_fxn(stack_t **head, unsigned int lnum)
{
	stack_t *ult, *penult;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul_fxn, stack too short\n", lnum);
		exit(EXIT_FAILURE);
	}

	ult = *head;
	penult = ult->next;

	penult->n = (penult->n) * (ult->n);

	*head = penult;
	penult->prev = NULL;
	free(ult);
}
