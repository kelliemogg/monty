#include "monty.h"

/**
 * print_q - prints queue
 * @h: list to print
 * Return: number of nodes
 */

size_t print_q(const stack_t *h)
{
	int count;

	for (count = 0; h != NULL; count++)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
	return (count);
}

/**
 * stack_len - returns length of list
 * @h: list
 * Return: length of list
 */

size_t stack_len(const stack_t *h)
{
	int count;

	for (count = 0; h != NULL; count++)
		h = h->next;
	return (count);
}

/**
 * add_stackstart - add node to beginning of linked list
 * @head: head of linked list
 * @n: value of node
 * Return: pointer to node or NULL
 */

stack_t *add_stackstart(stack_t **head, const int n)
{
	stack_t *new, *tmp;

	new = malloc(sizeof(stack_t));
	if (!new)
		return (NULL);
	new->prev = NULL;
	new->n = n;
	if (*head != NULL)
	{
		new->next = *head;
		tmp = new->next;
		tmp->prev = new;
	}
	else
		new->next = NULL;
	*head = new;
	return (new);
}

/**
 * push_stack - adds node to end
 * @head: head of linked list
 * @n: value to put into node
 * Return: pointer to node or NULL
 */

stack_t *push_stack(stack_t **head, const int n)
{
	stack_t *new, *node = *head;

	new = malloc(sizeof(stack_t));
	if (!new)
		return (NULL);
	if (*head == NULL)
	{
		new->prev = NULL;
		new->next = NULL;
		new->n = n;
		*head = new;
		return (new);
	}
	while (node->next != NULL)
	{
		node = node->next;
	}
	new->prev = node;
	new->next = NULL;
	new->n = n;
	node->next = new;
	return (new);
}

/**
 * free_stack - frees doubly linked list
 * @head: head of linked list
 * Return: null
 */

void free_stack(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}