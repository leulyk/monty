#include "monty.h"

/**
 * stackf - set the format of the data to a stack (LIFO)
 * this is the default behavior of the program
 *
 * @stack: pointer to the stack to manipulate
 * @line_number: current line number in the bytecode file
 *
 * When switching mode:
 *   The top of the stack becomes the front of the queue
 *   The front of the queue becomes the top of the stack
 *
 */
void stackf(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

}

/**
 * queue - set the format of the data to a queue (FIFO)
 *
 * @stack: pointer to the stack to manipulate
 * @line_number: current line number in the bytecode file
 *
 * When switching mode:
 *   The top of the stack becomes the front of the queue
 *   The front of the queue becomes the top of the stack
 *
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

}
