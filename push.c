#include "monty.h"

/**
 * push_fxn - add element to the stack
 * @head: head pointer.
 * @lnum: the current line number
 * @elem: the element to push onto the stack or queue.
 */
void push_fxn(stack_t **head, unsigned int lnum, int elem)
{
	(void) lnum;

	if (strcmp(flip, "queue") == 0)
		end_node_add(head, elem);
	else if (strcmp(flip, "stack") == 0)
		begin_node_add(head, elem);
}
