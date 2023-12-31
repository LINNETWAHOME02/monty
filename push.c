#include "monty.h"
/**
 * push - Pushes an element into the stack
 * @stack: The stack
 * @value: Element to be inserted
 *
 * Return: Nothing
 */
void push(stack_t **stack, int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	
	if (!new_node)
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
