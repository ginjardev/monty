#include "monty.h"
train_t train = {NULL, NULL, NULL, 0};

/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	ssize_t read_stream = 1;
	char *content;
	size_t buff = 0;
	FILE *file;
	unsigned int count = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	train.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	do {
		content = NULL;
		read_stream = getline(&content, &buff, file);
		train.streamptr = content;
		count++;

		if (read_stream > 0)
		{
			run(content, &stack, count, file);
		}

		free(content);
	} while (read_stream > 0);

	freestk(stack);
	fclose(file);
return (0);
}
