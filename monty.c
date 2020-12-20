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
	printf("We've done literally nothing\n");
	if (argc < 1)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	printf("About to enter opcode loop\n");
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
	stack_tt *stack = NULL;
	unsigned int line_number = 0;
	int characters, i;
	char *linebuff = NULL;
	size_t buffsize;
	FILE *fp = fopen(argv[1], "r");

	printf("Entering opcode loop function\n");
	if(!fp)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	printf("before first getline\n");
	characters = getline(&linebuff, &buffsize, fp);
	printf("Before getline while loop\n");
	while (characters >= 0)
	{
		for (i = 0; linebuff[i] != '\0'; i++)
		{
			if (linebuff[i] == '\n' && linebuff[i + 1] == '\0')
				linebuff[i] = '\0';
		}
		printf("linebuff is [%s]\n", linebuff);
		line_number++;
		tokenize(&stack, linebuff);
		linebuff = NULL;
		characters = getline(&linebuff, &buffsize, fp);
	}
	fclose(fp);
	free(linebuff);
	printf("after getline while loop\n");
	free_stack(stack);
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
	char *linebuff = NULL, *nbuff = NULL;
	int n = 0;

	linebuff = strtok(line, " ");
	if (!linebuff)
	{
		exit(0);
	}
	printf("linebuff set as [%s]\n", linebuff);
	nbuff = linebuff;
	while (nbuff != NULL)
	{
		nbuff = strtok(NULL, " ");
		if (nbuff != NULL)
		{
			printf("nbuff set as %s\n", nbuff);
			n = atoi(nbuff);
			printf("n set as %d\n", n);
			opcode_finder(stack, linebuff);
		}
		else
			opcode_finder(stack, linebuff);
	}
	printf("before token frees\n");
	if (nbuff)
		free(nbuff);
	if (linebuff)
		free(linebuff);
	printf("after token frees\n");
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

	printf("Entered opcodes with linebuff [%s]\n", linebuff);
	if (linebuff != NULL)
	{
		for (i = 0; arr[i].f; i++)
		{
			printf("arr[i].f is %s\n", arr[i].opcode);
			if (strcmp(linebuff, arr[i].opcode) == 0)
			{
				printf("found a match\n");
				arr[i].f(stack, line_number);
				return (1);
			}
		}
	}
	printf("L%d: unknown instruction %s\n", line_number, linebuff);
	exit(EXIT_FAILURE);
}
