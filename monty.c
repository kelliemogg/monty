#include "monty.h"

vars *first;

/**
 * main - main
 * description: main
 * @argc: argc
 * @argv: argv
 * Return: 0
 */

int main(int argc, char **argv)
{
	first = malloc(sizeof(vars));
	if (!first)
		return (-1);
	first->n = 0;
	first->error_code = 0;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	opcode_loop(argv);
	return (0);
}

/**
 * opcode_loop - interpreter
 * description: this takes input
 * @argv: argv
 * Return: 0
 */

int opcode_loop(char **argv)
{
	stack_tt *stack = NULL;
	unsigned int line_number = 0;
	int characters, i, tok, err;
	char *linebuff = NULL;
	size_t buffsize;
	FILE *fp = fopen(argv[1], "r");

	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	characters = getline(&linebuff, &buffsize, fp);
	while (characters >= 0)
	{
		for (i = 0; linebuff[i] != '\0'; i++)
		{
			if (linebuff[i] == '\n' && linebuff[i + 1] == '\0')
				linebuff[i] = '\0';
		}
		line_number++;
		tok = tokenize(&stack, linebuff, line_number);
		if (tok == -1)
			break;
		if (linebuff != NULL)
			free(linebuff);
		linebuff = NULL;
		if (first->error_code == -1)
			break;
		characters = getline(&linebuff, &buffsize, fp);
	}
	err = first->error_code;
	fclose(fp);
	if (linebuff != NULL)
		free(linebuff);
	free_stack(stack);
	free(first);
	if (err == -1)
		exit(EXIT_FAILURE);
	return (0);
}

/**
 * tokenize - tokenize
 * description: tokenize
 * @line: line
 * @stack: dbl ptr to stack
 * @line_number: ln count for errors
 * Return: 0
 */

int tokenize(stack_tt **stack, char *line, unsigned int line_number)
{
	char *linebuff = NULL, *nbuff = NULL;
	int b = 0;

	linebuff = strtok(line, " ");
	if (!linebuff)
	{
		return (0);
	}
	nbuff = linebuff;
	nbuff = strtok(NULL, " ");
	if (nbuff != NULL)
	{
		first->n = atoi(nbuff);
		b = opcode_finder(stack, linebuff, line_number);
	}
	else if (b != 1)
	{
		if (strcmp(linebuff, "push") == 0)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, linebuff);
			return (-1);
		}
			b = opcode_finder(stack, linebuff, line_number);
	}
	return (first->n);
}


/**
 * opcode_finder - finds proper opcode
 * description: str compares opcode for correlating func
 * @stack: dbl ptr to stack
 * @linebuff: linebuff
 * @line_number: ln count for errors
 * Return: 0 or 1
 */


int opcode_finder(stack_tt **stack, char *linebuff, unsigned int line_number)
{
	int i;

	instruction_tt arr[] = {
		{"push", pushit},
		{"pall", pallit},
		{"pint", pintit},
		{"pop", popit},
		{"swap", swapit},
		{"add", addit},
		{"nop", nope},
		{"sub", subit},
		{"div", divit},
		{"mul", mullet},
		{"mod", modit},
		{"#", nope},
		{"\0", NULL}
	};

	if (linebuff != NULL)
	{
		for (i = 0; arr[i].f; i++)
		{
			if (strcmp(linebuff, arr[i].opcode) == 0)
			{
				arr[i].f(stack, line_number);
				return (1);
			}
			else if (linebuff[0] == '#')
			{
				arr[11].f(stack, line_number);
				return (1);
			}
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, linebuff);
	exit(EXIT_FAILURE);
}
