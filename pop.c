#include "monty.h"
/**
 * pop_fxn - deletes/removes the head element.
 * @head: head pointer
 * @lnum: is current line number
 */
void pop_fxn(stack_t **head, unsigned int lnum)
{
	stack_t *tmp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pop_fxn an empty stack\n", lnum);
		exit(EXIT_FAILURE);
	}

	tmp = *head;
	*head = (*head)->next;
	if (*head != NULL)
		(*head)->prev = NULL;

	free(tmp);
}
