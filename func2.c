#include "monty.h"

/**
 *
 *
 *
 *
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

void nope(stack_tt **stack, unsigned int line_number)
{
	(void) stack;
	(void)line_number;

	return;
}
