#include "monty.h"

/**
 * addit - adds data
 * description: adds the value from top two elements
 * @stack: dbl ptr to a stack
 * @line_number: ln count for errors
 * Return: void
 */

void addit(stack_tt **stack, unsigned int line_number)
{
	stack_tt *itr = *stack, *prev = NULL;
	int value_one = 0, value_two = 0;

	if ((*stack == NULL) || (itr->next == NULL))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	for (; itr->next != NULL; itr = itr->next)
		;
	value_one = itr->n;
	prev = itr->prev;
	value_two = prev->n;
	prev->n = value_one + value_two;
	popit(stack, line_number);
}

/**
 * nope - nop opcode
 * description: doesn't do a thing
 * @stack: dbl ptr to stack
 * @line_number: ln count for errors
 * Return: void
 */
void nope(stack_tt **stack, unsigned int line_number)
{
	(void) stack;
	(void)line_number;

}

/**
* subit - adds data
* description: adds the value from top two elements
* @stack: dbl ptr to a stack
* @line_number: ln count for errors
* Return: void
*/

void subit(stack_tt **stack, unsigned int line_number)
{
	stack_tt *itr = *stack, *prev = NULL;
	int value_one = 0, value_two = 0;

	if ((*stack == NULL) || (itr->next == NULL))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	for (; itr->next != NULL; itr = itr->next)
		;
	value_one = itr->n;
	prev = itr->prev;
	value_two = prev->n;
	prev->n = value_one - value_two;
	popit(stack, line_number);
}

/**
 * mullet - multiplies top two numbers and pop top of stack
 * @stack: head of stack
 * @line_number: line number in file
 * Return: void
 */

void mullet(stack_tt **stack, unsigned int line_number)
{
	stack_tt *itr = *stack, *prev = NULL;
	int value_one = 0, value_two = 0;

	if ((*stack == NULL) || (itr->next == NULL))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	for (; itr->next != NULL; itr = itr->next)
		;
	value_one = itr->n;
	prev = itr->prev;
	value_two = prev->n;
	prev->n = value_one * value_two;
	popit(stack, line_number);
}

/**
 * divit - adds data
 * description: divides the value from top two elements
 * @stack: dbl ptr to a stack
 * @line_number: ln count for errors
 * Return: void
 */

void divit(stack_tt **stack, unsigned int line_number)
{
	stack_tt *itr = *stack, *prev = NULL;
	int value_one = 0, value_two = 0;

	if ((*stack == NULL) || (itr->next == NULL))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	for (; itr->next != NULL; itr = itr->next)
		;
	value_one = itr->n;
	prev = itr->prev;
	value_two = prev->n;
	if (value_one == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	prev->n = value_two / value_one;
	popit(stack, line_number);
}
