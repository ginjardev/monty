#include "monty.h"
/**
 * pstr_fxn - prints the stack starting at head.
 * @head: Head pointer.
 * @lnum: Current line number.
 */
void pstr_fxn(stack_t **head, unsigned int lnum)
{
	stack_t *tmp;
	(void) lnum;

	/* If the list is empty, print only a new line */
	if (*head == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *head;
	while (tmp != NULL && tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n < 127))
	{
		printf("%c", (char)tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}
