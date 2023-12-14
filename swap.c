#include "monty.h"
/**
 * swap_fxn - swaps the top two elements of the stack.
 * @head: head of stack
 * @counter: line_number
 * Return: no return
*/
void swap_fxn(stack_t **head, unsigned int counter)
{
	stack_t *s;
	int inc = 0, temp;

	s = *head;
	while (s)
	{
		s = s->next;
		inc++;
	}
	if (inc < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(train.file);
		free(train.streamptr);
		freestk(*head);
		exit(EXIT_FAILURE);
	}
	s = *head;
	temp = s->n;
	s->n = s->next->n;
	s->next->n = temp;
}
