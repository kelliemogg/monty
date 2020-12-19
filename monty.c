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
		fprintf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
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

int opcode_loop(char **argv)
{
	int line_number = 0, userinput, characters;
	char *linebuf;
	size_t buffsize;
	FILE *fp = fopen(argv[1], 0_RDONLY);

	if(!fp)
	{
		fprintf("Error: Can't open file %s\n", fp);
		exit(EXIT_FAILURE);
	}
	characters = getline(&linebuff, &buffsize, fp);
	while (characters >= 0)
	{
		line_number++;
		argv = tokenize(buffer);
		if (argv[0] == NULL)
			continue;
		if (opcode_finder(argv) == 1)
		{
			free(argv);
			continue;
		}
		characters = getline(&linebuff, &buffsize, fp);
	}
	free(linebuff);
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

	char *linebuff;

	linebuff = strtok(line, " ");
	if (!linebuff)
	{
		exit(0);
	}

	instructions->opcode = linebuff;

	while (linebuff != NULL)
	{
		linebuff = strtok(NULL, " ");
		if (!linebuff)
			break;
	}
	free(linebuff);
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
		{"push", pushit}
		{"pall", pallit}
		{"pint", pintit}
		{"pop", popit}
		{"swap", swapit}
		{"add", addit}
		{"nop", nope}
		{"sub", subit}
		{"div", divit}
		{"mul", mullet}
		{"mod", modit}
		{"pchar", pcharit}
		{"pstr", pstrit}
		{"rotl", rotlit}
		{"rotr", rotrit}
		{"stack", stackit}
		{"queue", queueit}
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
	fprintf("L%d: unknown instruction %s\n", line_number, argv);
	exit(EXIT_FAILURE)
}
