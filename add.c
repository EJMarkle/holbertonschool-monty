#include "monty.h"
/**
 * add - adds the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number where instructions appear
 * Return: Nothing
*/
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	int sum = (*stack)->n + (*stack)->next->n;

	pop(stack, line_number);
	(*stack)->n = sum;
}
