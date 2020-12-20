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
	int n = 0;
	stack_tt *new, *tail = *stack;
	(void) line_number;

	printf("Entered push\n");
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
/*	tail = new;
 */	printf("pushed %d to tail\n", new->n);
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
	stack_tt *itr;
	(void) line_number;

	printf("Before pall\n");
	for (itr = *stack; itr != NULL; itr = itr->next)
		printf("%d\n", itr->n);
	for (; itr != NULL; itr = itr->prev)
		printf("%d\n", itr->n);
	printf("After pall\n");
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

        for (itr = *stack; itr != NULL; itr = itr->next)
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

	if (*stack == NULL)
	{
		printf("L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
        for (itr = *stack; itr != NULL; itr = itr->next)
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
	stack_tt *itr;
	int holdt, holdp;
	int len;

	for (len = 1, itr = *stack; itr != NULL; len++, itr = itr->next)
                ;
	if (len < 2)
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	holdt = itr->n;
	itr = itr->prev;
	holdp = itr->n;
	itr->n = holdt;
	itr->n = holdp;
}
