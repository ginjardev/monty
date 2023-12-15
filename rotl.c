#include "monty.h"
/**
  *rotl_fxn- rotates the stack to the top
  *@head: head of stack
  *@counter: line_number
  *Return: none
 */
void rotl_fxn(stack_t **head,  __attribute__((unused)) unsigned int counter)
{
	stack_t *temp = *head, *rot;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	rot = (*head)->next;
	rot->prev = NULL;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = temp;
	(*head) = rot;
}
