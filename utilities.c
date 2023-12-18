#include "monty.h"

/**
 * begin_node_add - adds a new node to list
 * @head: head of linked list
 * @elem: element to be stored in new node
 */
void begin_node_add(stack_t **head, int elem)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = elem;
	new->prev = NULL;
	new->next = *head;

	if (*head != NULL)
		(*head)->prev = new;
	*head = new;
}

/**
 * end_node_add - adds a new node at the end of list.
 * @head: head of linked list
 * @elem: element to be stored in new node
 */
void end_node_add(stack_t **head, int elem)
{
	stack_t *new, *current;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = elem;
	new->prev = NULL;
	new->next = NULL;

	if (*head == NULL)
		*head = new;
	else
	{
		current = *head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new;
		new->prev = current;
	}
}

/**
 * _isdigit - checks if a given string is an integer.
 * @str: the string to be tested.
 *
 * Return: 1 if is an integer; otherwise 0.
 */
int _isdigit(char *str)
{
	int n = 0;

	if (str[0] == '-')
		str++;

	while (str[n] != '\0')
	{
		if (str[n] < '0' || str[n] > '9')
			return (0);
		n++;
	}

	return (1);
}

/**
 * stack_fxn - Sets the execution mode to "stack".
 * @head: a double pointer to the stack(unused).
 * @lnum: The line number.
 */
void stack_fxn(stack_t **head, unsigned int lnum)
{
	(void) head;
	(void) lnum;

	flip = "stack";
}

/**
 * queue_fxn - Sets the execution mode to "queue".
 * @head: a double pointer to queue(unused).
 * @lnum: The line number.
 */
void queue_fxn(stack_t **head, unsigned int lnum)
{
	(void) head;
	(void) lnum;

	flip = "queue";
}
