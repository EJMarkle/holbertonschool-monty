#include "monty.h"
/**
 * main - monty interpreter
 * @argc: argument count
 * @argv: argument value
 * Return: 1
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s file\n", argv[0]);
		return (EXIT_FAILURE);
	}
	FILE *file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	stack_t *stack = NULL;

	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 1;

	while (getline(&line, &len, file) != -1)
	{
		line[strcspn(line, "\n")] = '\0';
		parse_and_execute_instruction(&stack, line, line_number);
		line_number++;
	}

	free(line);
	fclose(file);
	return (EXIT_SUCCESS);
}
