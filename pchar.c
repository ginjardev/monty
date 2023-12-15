#include "monty.h"
/**
 * pchar_fxn - prints the char at the top of the stack,
 * followed by a new line
 * @head: head of stack
 * @counter: the number of the line
 * Return: none
*/
void pchar_fxn(stack_t **head, unsigned int counter)
{
	stack_t *ptr;

	ptr = *head;
	if (!ptr)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(train.file);
		free(train.streamptr);
		freestk(*head);
		exit(EXIT_FAILURE);
	}
	if (ptr->n > 127 || ptr->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		fclose(train.file);
		free(train.streamptr);
		freestk(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", ptr->n);
}
