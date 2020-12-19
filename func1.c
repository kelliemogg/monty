#include "monty.h"

/**
 *
 *
 *
 *
 *
 */

void pushit(stack_t **stack, unsigned int line_number)
{
	stack_t *endnode;
	stack_t *tail;

	endnode = malloc(sizeof(stack_t));
	if (endnode == NULL)
		return (NULL);
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
	return (1);
}

/**
 * pallit - prints linked list backwards
 *
 *
 *
 */
void pallit(stack_t **stack, unsigned int line_number)
{
	stack_t *itr;

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
void pintit(stack_t **stack, unsigned int line_number)
{
	stack_t *itr;

        for (itr = *stack; itr != NULL; itr = itr->next)
		;
	printf("%d\n", itr->n);
}

/**
 * popit - Removes node at end
 *
 *
 */

void popit(stack_t **stack, unsigned int line_number)
{
	stack_t *itr, *tmp;

	if (*stack == NULL)
	{
		fprintf("L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
        for (itr = *stack; itr != NULL; itr = itr->next)
                ;
	tmp = itr>prev;
	free(itr);
	tmp->next = NULL;
	Tail = tmp;
}

/**
 * swapit - swaps top two in stack
 *
 *
 *
 */

void swapit(stack_t **stack, unsigned int line_number)
{
	stack_t *itr, *holdt, *holdp;
	int len;

	for (len = 1, itr = *stack; itr != NULL; len++, itr = itr->next)
                ;
	if (len < 2)
	{
		fprintf("L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	holdt = itr->n;
	itr = itr->prev;
	holdp = itr->n;
	itr->n = holdt;
	itr->n = holdp;
}
