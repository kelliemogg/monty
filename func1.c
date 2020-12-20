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
	stack_tt *endnode;
	stack_tt *tail;
	(void) line_number;

	endnode = malloc(sizeof(stack_tt));
	if (endnode == NULL)
		return;
	endnode->n = n;
	if (*stack == NULL)
		*stack = endnode;
	else
	{
		tail = *stack;
		while (tail->next != NULL)
			tail = tail->next;
		tail->next = endnode;
		endnode->prev = tail;
		endnode->next = NULL;
		endnode = tail;
	}
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

	for (itr = *stack; itr != NULL; itr = itr->next)
		;
	for (; itr != NULL; itr = itr->prev)
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
