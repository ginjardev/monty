#ifndef MONTY_H
#define MONTY_H
#define  _GNU_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/* Switches mode between stacking and queuing */
extern char *flip;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Stack operations functions */
void push_fxn(stack_t **head, unsigned int lnum, int elem);
void pall_fxn(stack_t **head, unsigned int lnum);
void pint_fxn(stack_t **head, unsigned int lnum);
void pop_fxn(stack_t **head, unsigned int lnum);

/* Stack calculations functions */
void add_fxn(stack_t **head, unsigned int lnum);
void sub_fxn(stack_t **head, unsigned int lnum);
void div_fxn(stack_t **head, unsigned int lnum);
void mul_fxn(stack_t **head, unsigned int lnum);
void mod_fxn(stack_t **head, unsigned int lnum);

/* Stack manipulations functions */
void swap_fxn(stack_t **head, unsigned int lnum);
void pchar_fxn(stack_t **head, unsigned int n);
void pstr_fxn(stack_t **head, unsigned int lnum);
void rotl_fxn(stack_t **head, unsigned int lnum);
void rotr_fxn(stack_t **head, unsigned int lnum);

/* Linked lists operations */
void begin_node_add(stack_t **head, int elem);
void end_node_add(stack_t **head, int elem);


/* Execute */
void run(char *opcode, char *elem, stack_t **head, unsigned int n);

/* helpers */
void nop_fxn(stack_t **head, unsigned int lnum);
int _isdigit(char *str);
void stack_fxn(stack_t **head, unsigned int lnum);
void queue_fxn(stack_t **head, unsigned int lnum);
void freestk(stack_t **head);


#endif /* MONTY_H */
