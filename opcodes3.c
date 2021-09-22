#include <stdlib.h>
#include <stdio.h>
#include "monty.h"

/**
 * nop - does nothing
 *
 * @stack: pointer to the stack to manipulate
 * @line_number: current line number in the bytecode file
 */
void nop(__attribute__((unused)) stack_t **stack,
	__attribute__((unused)) unsigned int line_number) {}

/**
 * pchar - print the char at the top of the stack
 *
 * @stack: pointer to the stack to manipulate
 * @line_number: current line number in the bytecode file
 *
 * Description: if the element at the top of the stack is not in the ascii
 * table or if stack is empty exit with status of EXIT_FAILURE.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 32 || (*stack)->n > 255)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (char)(*stack)->n);
}

/**
 * pstr - print the string at the top of the stack
 *
 * @stack: pointer to the stack to manipulate
 * @line_number: current line number in the bytecode file
 *
 * Description: if stack is empty, print only a new line
 * The string stops when the stack is over, or the value of the element
 * is 0 or the value of the element is not in the ascii table
 */
void pstr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		printf("\n");
	}
	else
	{
		while (temp && (temp->n > 0 && temp->n <= 255))
		{
			printf("%c", (char)temp->n);
			temp = temp->prev;
		}
		printf("\n");
	}
}

/**
 * rotl - rotate the stack to the top
 *
 * @stack: pointer to the stack to manipulate
 * @line_number: current line number in the bytecode file
 *
 * Description: the top element becomes the last one, the second top element
 * becomes the first one. rotl never fails.
 */
void rotl(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *newhead;

	if (*stack && (*stack)->prev)
	{
		newhead = *stack;
		*stack = (*stack)->prev;
		(*stack)->next = NULL;

		newhead->next = opstack_head;
		newhead->prev = NULL;
		opstack_head->prev = newhead;
		opstack_head = newhead;
	}
}

/**
 * rotr - rotate the stack to the bottom
 *
 * @stack: pointer to the stack to manipulate
 * @line_number: current line number in the bytecode file
 *
 * Description: the last element becomes the top one. rotr never fails.
 */
void rotr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *newtail;

	if (opstack_head && opstack_head->next)
	{
		newtail = opstack_head;
		opstack_head = opstack_head->next;
		opstack_head->prev = NULL;
		newtail->next = NULL;

		(*stack)->next = newtail;
		newtail->prev = (*stack);
		opstack_tail = newtail;
	}
}
