#include "monty.h"
/**
 * add_fxn - adds the top two elements of the stack.
 * @head: head of stack
 * @counter: line number
 * Return: none
*/
void add_fxn(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	int length = 0, add;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(train.file);
		free(train.streamptr);
		freestk(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	add = temp->n + temp->next->n;
	temp->next->n = add;
	*head = temp->next;
	free(temp);
}
