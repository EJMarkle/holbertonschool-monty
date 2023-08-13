#include "monty.h"
/**
 * push - pushes an element to the stack
 * @stack: stack to push to
 * @line_number: line to push
 * Return: 1
 */

void push(stack_t **stack, unsigned int line_number)
{
	char *argument = NULL;

	if (argument == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->next = *stack;
	new_node->prev = NULL;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}
