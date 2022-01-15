#include "monty.h"

/**
 *mod - find the mod of the top two elements of the stack
 *
 *@stack: stack of elements
 *@cmd: cmd
 */
void mod(stack_t **stack, cmd_t cmd)
{
	int sum;
	stack_t *new;

	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%lu: can't mod, stack too short\n", cmd.line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%lu: division by zero\n", cmd.line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	new = (*stack)->next;

	sum = new->n;
	sum %= (*stack)->n;

	delete_node(stack, 0);
	new->n = sum;
}
