#include "monty.h"
/**
 * pall - prints all the values on the stack,
 * starting from the top of the stack.
 *
 * @stack: The stack
 * @line_number: line number on which the element is being printed
 *
 * Return: Nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	
	(void)line_number;
	
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
