#include "monty.h"

/* Default mode: "stack" */
char *flip = "stack";

/**
 * main - main function to run monty
 * @argc: number of arguments
 * @argv: list of arguments as strings
 *
 * Return: 0 if success.
 */
int main(int argc, char *argv[])
{
	stack_t *head = NULL;
	size_t buff = 0, lnum = 0;
	char *line = NULL, *opcode, *elem;
	FILE *file;
	int status;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	do {
		lnum++;
		if (getline(&line, &buff, file) == -1)
			break;

		opcode = strtok(line, " \t\n");
		elem = strtok(NULL, " \t\n");

		if (opcode[0] == '#' || !opcode)
			continue;

		run(opcode, elem, &head, lnum);
		status = 1;
	} while (status);

	fclose(file);
	free(line);
	freestk(&head);

	return (EXIT_SUCCESS);
}
