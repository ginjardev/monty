#include "monty.h"
/**
 * pchar_fxn - prints the char at the head of the stack/queue.
 * @head: Head pointer.
 * @n: Current line number.
 */
void pchar_fxn(stack_t **head, unsigned int n)
{
	int askey_val;

	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", n);
		exit(EXIT_FAILURE);
	}

	askey_val = (*head)->n;

	if (askey_val < 0 || askey_val > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", n);
		exit(EXIT_FAILURE);
	}

	putchar((char)askey_val);
	putchar('\n');
}
