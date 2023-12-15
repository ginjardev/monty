#include "monty.h"
/**
 * pop_fxn - pops the top of stack
 * @head: stack head
 * @counter: line number
 * Return: none
*/
void pop_fxn(stack_t **head, unsigned int counter)
{
	stack_t *temp;

	if (*head == NULL)
	{
		handle_pop_error(counter, *head);
	}

	temp = *head;
	*head = temp->next;
	free(temp);
}

/**
 * handle_pop_error - error handling for push
 * @head: head of the stack
 * @counter: line number
 * Return: none
*/
void handle_pop_error(unsigned int counter, stack_t *head)
{
	fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
	fclose(train.file);
	free(train.streamptr);
	freestk(head);
	exit(EXIT_FAILURE);
}
