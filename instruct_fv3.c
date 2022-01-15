#include "monty.h"

/**
 *mod - find the mod of the top two elements of the stack
 *
 *@stack: stack of elements
 *@cmd: cmd
 **/
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


/**
 *pchar - prints the char at the top of the stack,
 *followed by a new line
 *
 *@stack: double pointer
 *@cmd: cmd
 **/
void pchar(stack_t **stack, cmd_t cmd)
{
	if (*stack)
	{
		if ((*stack)->n >= 0 && (*stack)->n <= 127)
			printf("%c\n", (*stack)->n);
		else
		{
			fprintf(stderr, "L%lu: can't pchar, value out of range\n", cmd.line_number);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%lu: can't pchar, stack empty\n", cmd.line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}
