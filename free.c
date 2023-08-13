#include "monty.h"
/**
 * free_stack - frees the memory of all nodes in the stack
 * @stack: pointer to the top of the stack
 * Return: Nothing
*/
void free_stack(stack_t **stack)
{
	while (*stack != NULL)
	{
		stack_t *temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}
