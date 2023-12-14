#include "monty.h"
/**
 * pint_fxn - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void pint_fxn(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(train.file);
		free(train.streamptr);
		freestk(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
