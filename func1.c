#include "monty.h"

/**
 * pushit - push element to the stack
 * description: adds element to the stack
 * @stack: dbl ptr to a stack
 * @line_number: ln count for error
 * Return: void
 */

void pushit(stack_tt **stack, unsigned int line_number)
{
	stack_tt *new, *tail = *stack;
	int n = first->n;
	(void) line_number;

	new = malloc(sizeof(stack_tt));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		first->error_code = -1;
		return;
	}
	if (*stack == NULL)
	{
		new->prev = NULL;
		new->next = NULL;
		new->n = n;
		*stack = new;
		return;
	}
	while (tail->next != NULL)
		tail = tail->next;
	new->n = n;
	tail->next = new;
	new->prev = tail;
	new->next = NULL;
}

/**
 * pallit - print all
 * decription: prints linked list backwards
 * @stack: dbl ptr to stack
 * @line_number: ln count for errors
 * Return: void
 */
void pallit(stack_tt **stack, unsigned int line_number)
{
	int i = 0;
	stack_tt *itr;
	(void) line_number;

	if (*stack == NULL)
		return;
	for (itr = *stack; itr->next != NULL; itr = itr->next)
		i++;
	i++;
	for (; i != 0; itr = itr->prev, i--)
		printf("%d\n", itr->n);
}

/**
 * pintit - prints a value
 * description: prints value at top of stack
 * @stack: dbl ptr to stack
 * @line_number: ln count for errors
 * Return: void
 */
void pintit(stack_tt **stack, unsigned int line_number)
{
	stack_tt *itr;
	(void) line_number;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		first->error_code = -1;
		return;
	}
	for (itr = *stack; itr->next != NULL; itr = itr->next)
		;
	printf("%d\n", itr->n);
}

/**
 * popit - pops an element off the stack
 * description: removes top element
 * @stack: dbl ptr to stack
 * @line_number: ln count for errors
 * Return: void
 */

void popit(stack_tt **stack, unsigned int line_number)
{
	stack_tt *itr, *tmp;

	itr = *stack;
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		first->error_code = -1;
		return;
	}
	if (itr->next == NULL)
	{
		free(itr);
		*stack = NULL;
		return;
	}
	for (itr = *stack; itr->next != NULL; itr = itr->next)
		;
	tmp = itr->prev;
	free(itr);
	tmp->next = NULL;
}

/**
 * swapit - swaps elements
 * description: swaps top two elements in stack
 * @stack: dbl ptr to stack
 * @line_number: ln count for errors
 * Return: void
 */

void swapit(stack_tt **stack, unsigned int line_number)
{
	stack_tt *itr, *prev;
	int holdt, holdp;
	int len;

	itr = *stack;
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		first->error_code = -1;
		return;
	}
	for (len = 1, itr = *stack; itr->next != NULL; len++, itr = itr->next)
		;
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		first->error_code = -1;
		return;
	}
	holdt = itr->n;
	prev = itr->prev;
	holdp = prev->n;
	itr->n = holdp;
	prev->n = holdt;
}
