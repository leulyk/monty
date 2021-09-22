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
	(void) stack;
	(void) line_number;

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
void pstr(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
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
void rotl(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

}

/**
 * rotr - rotate the stack to the bottom
 *
 * @stack: pointer to the stack to manipulate
 * @line_number: current line number in the bytecode file
 *
 * Description: the last element becomes the top one. rotr never fails.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

}
