#include "monty.h"
/**
 * mod_fxn - modulo
 * @head: head of stack
 * @counter: number of lines
 * Return: none
*/
void mod_fxn(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int num = 0, temp;

	h = *head;
	while (h)
	{
		h = h->next;
		num++;
	}
	if (num < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(train.file);
		free(train.streamptr);
		freestk(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(train.file);
		free(train.streamptr);
		freestk(*head);
		exit(EXIT_FAILURE);
	}
	temp = h->next->n % h->n;
	h->next->n = temp;
	*head = h->next;
	free(h);
}
