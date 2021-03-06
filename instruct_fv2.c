#include "monty.h"

/**
 *add - adds the top two elements of the stack
 *
 *@stack: stack of elements
 *@cmd: cmd
 */
void add(stack_t **stack, cmd_t cmd)
{
	int sum;
	stack_t *new;

	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%lu: can't add, stack too short\n", cmd.line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	new = (*stack)->next;

	sum = (*stack)->n;
	sum += (*stack)->next->n;

	delete_node(stack, 0);
	new->n = sum;
}


/**
 *sub - subtracts the top two elements of the stack
 *
 *@stack: stack of elements
 *@cmd: cmd
 */
void sub(stack_t **stack, cmd_t cmd)
{
	int sum;
	stack_t *new;

	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%lu: can't sub, stack too short\n", cmd.line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	new = (*stack)->next;

	sum = new->n;
	sum -= (*stack)->n;

	delete_node(stack, 0);
	new->n = sum;
}


/**
 *divide - divide the top two elements of the stack
 *
 *@stack: stack of elements
 *@cmd: cmd
 */
void divide(stack_t **stack, cmd_t cmd)
{
	int sum;
	stack_t *new;

	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%lu: can't div, stack too short\n", cmd.line_number);
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
	sum /= (*stack)->n;

	delete_node(stack, 0);
	new->n = sum;
}

/**
 *mul - multiply the top two elements of the stack
 *
 *@stack: stack of elements
 *@cmd: cmd
 */
void mul(stack_t **stack, cmd_t cmd)
{
	int sum;
	stack_t *new;

	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%lu: can't mul, stack too short\n", cmd.line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	new = (*stack)->next;

	sum = new->n;
	sum *= (*stack)->n;

	delete_node(stack, 0);
	new->n = sum;
}

/**
 *nop - doesn’t do anything
 *
 *@stack: stack of elements
 *@cmd: cmd
 */
void nop(stack_t **stack __attribute__((unused)),
cmd_t cmd __attribute__((unused)))
{
}
