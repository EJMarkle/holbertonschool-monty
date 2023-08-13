#include "monty.h"
/**
 * push - pushes an element on to the stack
 * @stack: pointer to the top of the stack
 * @line_number: where instructions appear
 * Return: Nothing
*/
void push(stack_t **stack, int line_number)
{
	char *arg = strtok(NULL, " \t\n");

	if (arg == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
	}

	char *endptr;
	long int value = strtol(arg, &endptr, 10);

	if (*endptr != '\0' && !isspace(*endptr))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

		new_node->n = value;
		new_node->prev = NULL;
		new_node->next = *stack;

	if (*stack != NULL)
	(*stack)->prev = new_node;
	*stack = new_node;
}
