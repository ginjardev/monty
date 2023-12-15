#include "monty.h"
/**
 * div_fxn - divides the top two elements of the stack.
 * @head: head of stack
 * @counter: line number
 * Return: none
*/
void div_fxn(stack_t **head, unsigned int counter)
{
	stack_t *k;
	int len = 0, temp;

	k = *head;
	while (k)
	{
		k = k->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(train.file);
		free(train.streamptr);
		freestk(*head);
		exit(EXIT_FAILURE);
	}
	k = *head;
	if (k->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(train.file);
		free(train.streamptr);
		freestk(*head);
		exit(EXIT_FAILURE);
	}
	temp = k->next->n / k->n;
	k->next->n = temp;
	*head = k->next;
	free(k);
}
