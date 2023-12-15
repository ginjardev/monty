#include "monty.h"
/**
  *rotr_fxn- rotates the stack to the bottom
  *@head: head of stack
  *@counter: the number of the line
  *Return: none
 */
void rotr_fxn(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *rot;

	rot = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (rot->next)
	{
		rot = rot->next;
	}
	rot->next = *head;
	rot->prev->next = NULL;
	rot->prev = NULL;
	(*head)->prev = rot;
	(*head) = rot;
}
