#include "monty.h"
/**
 * sub_fxn - subtracts the last (ultimate) of the stack or queue from the
 * second last (penultimate) element of the stack.
 * @head: pointer to head node.
 * @lnum: The line number.
 */
void sub_fxn(stack_t **head, unsigned int lnum)
{
	stack_t *ult, *penult;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", lnum);
		exit(EXIT_FAILURE);
	}

	ult = *head;
	penult = ult->next;

	penult->n = (penult->n) - (ult->n);

	*head = penult;
	penult->prev = NULL;
	free(ult);
}
