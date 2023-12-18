#include "monty.h"
/**
 * rotr_fxn - rotates the stack or queue to the last node.
 * @head: Head pointer.
 * @lnum: Current line number.
 */
void rotr_fxn(stack_t **head, unsigned int lnum)
{
	stack_t *current, *last;
	(void) lnum;

	if (*head == NULL || (*head)->next == NULL)
		return;

	current = *head;

	/* Traverse to find the current last element */
	while (current->next != NULL)
		current = current->next;

	last = current;

	/* Update pointers to rotate the list */
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = *head;
	(*head)->prev = last;

	/* Update the head to point to the new last element */
	*head = last;
}
