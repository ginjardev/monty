#include "monty.h"
/**
 * pall_fxn - prints the stack
 * @head: head of stack
 * @number: not used
 * Return: none
*/
void pall_fxn(stack_t **head, unsigned int number)
{
	stack_t *ptr = *head;
	(void)number;

	if (ptr == NULL)
		return;

	do {
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	} while (ptr);
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
		{
			j++;
		}
		while (train.c[j] != '\0')
		{
			if (train.c[j] > 57 || train.c[j] < 48)
			{
				flag = 1;
				break;
			}
			j++;
		}
		if (flag == 1)
		{
			handle_error(number, head);
		}
	}
	else
	{
		handle_error(number, head);
	}

	m = atoi(train.c);

	if (train.flip == 0)
	{
		add_node(head, m);
	}
	else
	{
		add_queue(head, m);
	}
}

/**
 * handle_error - error handling for push
 * @head: head of the stack
 * @number: the line number
 * Return: none
*/
void handle_error(unsigned int number, stack_t **head)
{
	fprintf(stderr, "L%d: usage: push integer\n", number);
	fclose(train.file);
	free(train.streamptr);
	freestk(*head);
	exit(EXIT_FAILURE);
}
