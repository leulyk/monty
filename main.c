#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "monty.h"

char *value = NULL;
stack_t *opstack_head = NULL, *opstack_tail = NULL;
/**
 * main - Entry point to the monty interpreter
 *
 * @argc: argument count
 * @argv: array of character strings as arguments
 *
 * Return: exits with status of EXIT_SUCCESS, or EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	char *opcode;
	int linecount = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &len, fp) != -1)
	{
		linecount++;
		opcode = strtok(line, " \n");
		if (opcode[0] == '#')
			continue;
		if (check_opcode(opcode) == 0)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", linecount, opcode);
			exit(EXIT_FAILURE);
		}
		value = strtok(NULL, " \n");
		execute_opcode(opcode, &opstack_tail, linecount);
	}
	free_dlistint(opstack_tail);
	free(opcode);
	free(value);

	return (EXIT_SUCCESS);
}

/**
 * check_opcode - check whether an opcode is valid
 *
 * @input: the character string to check
 *
 * Return: 1 if it's a valid opcode, otherwise 0
 */
int check_opcode(char *input)
{
	int i;
	char *opcodes[] = {
		"push", "pall", "pint", "pop", "swap", "add", "nop",
		"sub", "div", "mul", "mod", "pchar", "pstr", "rotl",
		"rotr", "stack", "queue", NULL
	};

	for (i = 0; opcodes[i]; ++i)
		if (strcmp(opcodes[i], input) == 0)
			return (1);
	return (0);
}

/**
 * execute_opcode - execute an opcode
 *
 * @opcode: the opcode to execute
 * @stack: doubly linked list to operate on
 * @line_n: current line number
 *
 */
void execute_opcode(char *opcode, stack_t **stack, unsigned int line_n)
{
	int i;
	instruction_t instructions[] = {
		{ "push", push },
		{ "pall", pall },
		{ "pint", pint },
		{ "pop", pop },
		{ "swap", swap },
		{ "add", add },
		{ "nop", nop },
		{ "sub", sub },
		{ "div", divide },
		{ "mul", mul },
		{ "mod", mod },
		{ "pchar", pchar },
		{ "pstr", pstr },
		{ "rotl", rotl },
		{ "rotr", rotr },
		{ "stack", stackf },
		{ "queue", queue },
		{ NULL, NULL }
	};

	for (i = 0; instructions[i].opcode; ++i)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_n);
			break;
		}
	}
}
