#ifndef MONTY_H
#define MONTY_H
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>
#include <strings.h>
#include <stddef.h>
#include <dirent.h>
#include <signal.h>

extern int line_number;

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



size_t print_q(const stack_t *h);
size_t stack_len(const stack_t *h);
stack_t *add_stackstart(stack_t **head, const int n);
stack_t *push_stack(stack_t **head, const int n);
void free_stack(stack_t *head);
stack_t *add_dnodeint_end(stack_t **head, const int n);
int opcode_finder(char **argv);

#endif /*MONTY_H*/
