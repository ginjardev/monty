#include "monty.h"
/**
 * pstr_fxn - prints the string starting at the top of the stack,
 * followed by a new line
 * @head: head of stack
 * @counter: line_number
 * Return: none
*/
void pstr_fxn(stack_t **head, unsigned int counter)
{
	stack_t *ptr;
	(void)counter;

	ptr = *head;
	do {
		if (ptr == NULL || ptr->n > 127 || ptr->n <= 0)
			break;
		printf("%c", ptr->n);
		ptr = ptr->next;
	} while (ptr != NULL);
	printf("\n");
}
