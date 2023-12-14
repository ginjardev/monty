#include "monty.h"
/**
 * pall_fxn - prints the stack
 * @head: head of stack
 * @number: not used
 * Return: none
*/
void pall_fxn(stack_t **head, unsigned int number)
{
	stack_t *h;
	(void)number;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
 * push_fxn - add node to the stack
 * @head: head of stack
 * @number: line_number
 * Return: no return
*/
void push_fxn(stack_t **head, unsigned int number)
{
	int m, j = 0, flag = 0;

	if (train.c)
	{
		if (train.c[0] == '-')
			j++;
		for (; train.c[j] != '\0'; j++)
		{
			if (train.c[j] > 57 || train.c[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", number);
			fclose(train.file);
			free(train.streamptr);
			freestk(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", number);
		fclose(train.file);
		free(train.streamptr);
		freestk(*head);
		exit(EXIT_FAILURE); }
	m = atoi(train.c);
	if (train.flip == 0)
		add_node(head, m);
	else
		add_queue(head, m);
}
