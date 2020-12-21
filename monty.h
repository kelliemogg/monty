#ifndef MONTY_H
#define MONTY_H
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>
#include <strings.h>
#include <stddef.h>
#include <fcntl.h>

extern int n;

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
} stack_tt;

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
	void (*f)(stack_tt **stack, unsigned int line_number);
} instruction_tt;



size_t print_q(const stack_tt *h);
size_t stack_len(const stack_tt *h);
stack_tt *add_stackstart(stack_tt **head, const int n);
stack_tt *push_stack(stack_tt **head, const int n);
void free_stack(stack_tt *stack);
stack_tt *add_dnodeint_end(stack_tt **head, const int n);
int opcode_finder(stack_tt **stack, char *linebuff, unsigned int line_number);
int opcode_loop(char **argv);
int tokenize(stack_tt **stack, char *line, unsigned int line_number);
void pushit(stack_tt **stack, unsigned int line_number);
void pallit(stack_tt **stack, unsigned int line_number);
void pintit(stack_tt **stack, unsigned int line_number);
void popit(stack_tt **stack, unsigned int line_number);
void swapit(stack_tt **stack, unsigned int line_number);
void addit(stack_tt **stack, unsigned int line_number);
void nope(stack_tt **stack, unsigned int line_number);
void subit(stack_tt **stack, unsigned int line_number);
void mullet(stack_tt **stack, unsigned int line_number);
void modit(stack_tt **stack, unsigned int line_number);
void divit(stack_tt **stack, unsigned int line_number);


#endif /*MONTY_H*/
