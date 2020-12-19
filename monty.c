#include "monty.h"

/**
 * main - main
 * description: main
 * @argc: argc
 * @argv: argv
 * Return: 0
 */

int main(int argc, char **argv)
{
	opcode_loop(argc, argv);
	return (0);
}

/**
 * opcode_loop - interpreter
 * description: this takes input
 * @argc: argc
 * @argv: argv
 * Return: 0
 */

int opcode_loop(int argc, char **argv)
{
	int line_number = 0;
	int userinput;
	(void) argc;

	while (1)
	{
		fopen(argv[1], 0_RDONLY);
		line_number++;
/* was get line but needs to read line */
		if (userinput == -1)
			break;
/* after we open file */		argv = tokenize(buffer);
		if (argv[0] == NULL)
			continue;
		if (opcode_finder(argv) == 1)
		{
			free(argv);
			continue;
		}
	}
	free_stack(head);
	return (0);
}

/**
 * tokenize - tokenize
 * description: tokenize
 * @line: line
 * Return: 0
 */

int **tokenize(char *line)
{

	char *linebuf;

	linebuf = strtok(line, " ");
	if (!linebuf)
	{
		exit(0);
	}

	instructions->opcode = linebuf;

	while (linebuf != NULL)
	{
		linebuf = strtok(NULL, " ");
		if (!linebuf)
			break;
	}
	return (n);
}




/**
 * opcode_finder - finds proper opcode
 * description: str compares opcode for correlating func
 * @argv: arg passed as opcode
 * Return: 0 or 1
 */


int opcode_finder(char **argv)
{
	int i;

	instructions_t arr[] = {
		{"push", push}
		{"pall", pall}
		{"pint", pint}
		{"pop", pop}
		{"swap", swap}
		{"add", add}
		{"nop", nop}
		{"sub", sub}
		{"div", div}
		{"mul", mul}
		{"mod", mod}
		{"pchar", pchar}
		{"pstr", pstr}
		{"rotl", rotl}
		{"rotr", rotr}
		{"stack", stack}
		{"queue", queue}
		{"\0", NULL}
	};

	if (argv != NULL)
	{
		for (i = 0; arr[i].func; i++)
		{
			if (strcmp(instructions->opcode, arr[i].argv) == 0)
			{
				arr[i].func();
				return (1);
			}
		}
	}
	return (0);
}
