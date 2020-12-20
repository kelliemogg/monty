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
	if (argc < 1)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	opcode_loop(argv);
	return (0);
}

/**
 * opcode_loop - interpreter
 * description: this takes input
 * @argc: argc
 * @argv: argv
 * Return: 0
 */

int opcode_loop(char **argv)
{
	stack_tt **stack;
	unsigned int line_number = 0;
	int characters;
	char *linebuff;
	size_t buffsize;
	FILE *fp = fopen(argv[1], "r");

	if(!fp)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	characters = getline(&linebuff, &buffsize, fp);
	while (characters >= 0)
	{
		stack = malloc(sizeof(stack_tt));
		line_number++;
		tokenize(stack, linebuff);
		characters = getline(&linebuff, &buffsize, fp);
	}
	free(linebuff);
/*	free_stack; */
	return (0);
}

/**
 * tokenize - tokenize
 * description: tokenize
 * @line: line
 * Return: 0
 */

int tokenize(stack_tt **stack, char *line)
{
	int n = 0;
	char *linebuff, *nbuff;

	linebuff = strtok(line, " ");
	if (!linebuff)
	{
		exit(0);
	}
	while (nbuff != NULL)
	{
		nbuff = strtok(NULL, " ");
		if (!nbuff)
			break;
		else
		{
			n = atoi(nbuff);
			opcode_finder(stack, linebuff);
		}
	}
	free(nbuff);
	free(linebuff);
	return (n);
}


/**
 * opcode_finder - finds proper opcode
 * description: str compares opcode for correlating func
 * @argv: arg passed as opcode
 * Return: 0 or 1
 */


int opcode_finder(stack_tt **stack, char *linebuff)
{
	unsigned int line_number = 1;
	int i;

	instruction_tt arr[] = {
		{"push", pushit},
		{"pall", pallit},
		{"pint", pintit},
		{"pop", popit},
		{"swap", swapit},
/*		{"add", addit},
		{"nop", nope},
		{"sub", subit},
		{"div", divit},
		{"mul", mullet},
		{"mod", modit},
		{"pchar", pcharit},
		{"pstr", pstrit},
		{"rotl", rotlit},
		{"rotr", rotrit},
		{"stack", stackit},
		{"queue", queueit}, */
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
		}
	}
	printf("L%d: unknown instruction %s\n", line_number, linebuff);
	exit(EXIT_FAILURE);
}
