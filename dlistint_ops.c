#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * add_dnodeint_end - add a node to the tail of a doubly linked list
 *
 * @tail: pointer to the tail node
 * @num: integer data of the new node
 *
 * Return: address of the new node
 */
stack_t *add_dnodeint_end(stack_t **tail, const int num)
{
	stack_t *newnode;
	stack_t *current = *tail;

	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	newnode->n = num;
	if (*tail == NULL)
	{
		*tail = opstack_head = newnode;
	}
	else
	{
		current->next = newnode;
		newnode->prev = current;
		opstack_tail = newnode;
	}

	return (newnode);
}

/**
 * free_dlistint - free a doubly linked list
 *
 * @tail: the tail node
 *
 */
void free_dlistint(stack_t *tail)
{
	stack_t *temp;

	if (tail == NULL)
		return;
	while (tail)
	{
		temp = tail->prev;
		free(tail);
		tail = temp;
	}
}
