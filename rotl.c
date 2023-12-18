#include "monty.h"
/**
 * rotl_fxn - rotates the stack or queue to first node
 * @head: Head pointer.
 * @lnum: Current line number.
 */
void rotl_fxn(stack_t **head, unsigned int lnum)
{
	stack_t *current;
	(void) lnum;

	if (*head == NULL || (*head)->next == NULL)
		return;

	current = *head;
	while (current->next != NULL)
		current = current->next;

	current->next = *head;
	(*head)->prev = current;
	*head = (*head)->next;
	(*head)->prev->next = NULL;
	(*head)->prev = NULL;
}

