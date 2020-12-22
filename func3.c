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
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		first->error_code = -1;
		return;
	}
	for (; itr->next != NULL; itr = itr->next)
		;
	value_one = itr->n;
	prev = itr->prev;
	value_two = prev->n;
	if (value_one == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		first->error_code = -1;
		return;
	}
	prev->n = value_two % value_one;
	popit(stack, line_number);
}

/**
 * pcharit - prints a value
 * description: prints value at top of stack
 * @stack: dbl ptr to stack
 * @line_number: ln count for errors
 * Return: void
 */
void pcharit(stack_tt **stack, unsigned int line_number)
{
	int n = 0;
	stack_tt *itr;
	(void) line_number;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		first->error_code = -1;
		return;
	}
	for (itr = *stack; itr->next != NULL; itr = itr->next)
	;
	if (itr->n >= 0 && itr->n <= 127)
	{
		n = itr->n;
		putchar(n);
		putchar('\n');
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		first->error_code = -1;
		return;
	}
}

/**
 * pstrit - print the string at the top of the stack
 * decription: prints the ascii of an int
 * @stack: dbl ptr to stack
 * @line_number: ln count for errors
 * Return: void
 */
void pstrit(stack_tt **stack, unsigned int line_number)
{
	int i = 0;
	stack_tt *itr;
	(void) line_number;

	if (*stack == NULL)
	{
		putchar('\n');
		return;
	}
	for (itr = *stack; itr->next != NULL; itr = itr->next)
		i++;
	i++;
	for (; i != 0; itr = itr->prev, i--)
	{
		if (itr->n == 0)
			break;
		if (itr->n < 0 || itr->n > 127)
			break;
		putchar(itr->n);
	}
	putchar('\n');
}
