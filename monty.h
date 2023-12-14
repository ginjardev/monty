#ifndef MONTY_H
#define MONTY_H
#define  _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct train_s - variables -c(argument), file, stream ptr
 * @c: vargument value
 * @file: pointer to monty file
 * @streamptr: pointer to content of stream
 * @flip: flag change from stack to queue
 * Description: moves values through the program like a train
 */
typedef struct train_s
{
	char *c;
	FILE *file;
	char *streamptr;
	int flip;
}  train_t;
extern train_t train;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


int run(char *streamptr, stack_t **stack, unsigned int linecnt, FILE *file);
void push_fxn(stack_t **head, unsigned int number);
void pall_fxn(stack_t **head, unsigned int number);
void pint_fxn(stack_t **head, unsigned int number);
void pop_fxn(stack_t **head, unsigned int counter);
void swap_fxn(stack_t **head, unsigned int counter);
void add_fxn(stack_t **head, unsigned int counter);
void nop_fxn(stack_t **head, unsigned int counter);
void freestk(stack_t *head);
void add_node(stack_t **head, int n);
void add_queue(stack_t **head, int n);

#endif
