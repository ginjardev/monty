#include "monty.h"
/**
  *sub_fxn- subtract first two
  *@head: head of stack
  *@counter: number of line
  *Return: none
 */
void sub_fxn(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	int nodes, sub;

	temp = *head;
	for (nodes = 0; temp != NULL; nodes++)
		temp = temp->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(train.file);
		free(train.streamptr);
		freestk(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	sub = temp->next->n - temp->n;
	temp->next->n = sub;
	*head = temp->next;
	free(temp);
}
