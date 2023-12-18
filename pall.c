#include "monty.h"
/**
 * pall_fxn - prints all elements of the stack/queue.
 * @head: head pointer.
 * @lnum: current line number
 */
void pall_fxn(stack_t **head, unsigned int lnum)
{
	stack_t *current;
	(void) lnum;

	if (lnum == 0 || *head == NULL)
		return;

	current = *head;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
