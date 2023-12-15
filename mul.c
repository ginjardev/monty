#include "monty.h"
/**
 * mul_fxn - multiplies the top two elements of the stack.
 * @head: head of stack
 * @counter: number of lines
 * Return: none
*/
void mul_fxn(stack_t **head, unsigned int counter)
{
	stack_t *ptr;
	int num = 0, temp;

	ptr = *head;
	while (ptr)
	{
		ptr = ptr->next;
		num++;
	}
	if (num < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(train.file);
		free(train.streamptr);
		freestk(*head);
		exit(EXIT_FAILURE);
	}
	ptr = *head;
	temp = ptr->next->n * ptr->n;
	ptr->next->n = temp;
	*head = ptr->next;
	free(ptr);
}
