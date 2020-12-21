#include "monty.h"

/**
 * modit - modulus of top values
 * description: remaider of second to top value divided by top value
 * becomes second to top value and top of stack is popped
 *
 * @stack: dbl ptr to a stack
 * @line_number: ln count for errors
 * Return: void
 */

void modit(stack_tt **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: division by zero", line_number);
		exit(EXIT_FAILURE);
	}
	prev->n = value_two % value_one;
	popit(stack, line_number);
}
