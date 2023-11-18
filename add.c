#include "monty.h"
/**
 * add - Adds the top two elements
 * @stack: Tne stack
 * @line_number: line number from which element is being printed from
 *
 * Return: Nothing
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}
