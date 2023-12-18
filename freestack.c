#include "monty.h"

/**
 * freestk - Frees the memory of a stack or queue.
 * @head: head pointer.
 */
void freestk(stack_t **head)
{
	stack_t *current, *tmp;

	current = *head;
	do {
		tmp = current;
		current = current->next;
		free(tmp);
	} while (current != NULL);
}
