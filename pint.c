#include "monty.h"
/**
 * pint_fxn - prints the top
 * @head: stack head
 * @number: line_number
 * Return: no return
*/
void pint_fxn(stack_t **head, unsigned int number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", number);
		fclose(train.file);
		free(train.streamptr);
		freestk(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
