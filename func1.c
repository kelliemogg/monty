#include "monty.h"

/**
 * pushit - push a node
 * description: push it real good
 * @stack: stackity stack
 * @line_number: don't come back
 * Return: void
 */

void pushit(stack_tt **stack, unsigned int line_number)
{
	stack_tt *new, *tail = *stack;
	(void) line_number;

	new = malloc(sizeof(stack_tt));
	if (new == NULL)
		return;
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
/*	tail = new; */
	return;
}

/**
 * pallit - prints linked list backwards
 *
 *
 *
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
 * pintit - prints tail of linked list
 *
 *
 *
 */
void pintit(stack_tt **stack, unsigned int line_number)
{
	stack_tt *itr;
	(void) line_number;

        for (itr = *stack; itr->next != NULL; itr = itr->next)
		;
	printf("%d\n", itr->n);
}

/**
 * popit - Removes node at end
 *
 *
 */

void popit(stack_tt **stack, unsigned int line_number)
{
	stack_tt *itr, *tmp;

	itr = *stack;
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
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
 * swapit - swaps top two in stack
 *
 *
 *
 */

void swapit(stack_tt **stack, unsigned int line_number)
{
	stack_tt *itr, *prev;
	int holdt, holdp;
	int len;

	for (len = 1, itr = *stack; itr->next != NULL; len++, itr = itr->next)
                ;
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	holdt = itr->n;
	prev = itr->prev;
	holdp = prev->n;
	itr->n = holdp;
	prev->n = holdt;
}
