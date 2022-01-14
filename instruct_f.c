#include "monty.h"
/**
 *push - pushes an element to the stack
 *
 * @stack: double pointer
 * @cmd: cmd
 */
void push(stack_t **stack, cmd_t cmd)
{
	stack_t *new;

	if (!cmd.data || is_number(cmd.data))
	{
		fprintf(stderr, "L%lu: usage: push integer\n", cmd.line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	new = new_node(atoi(cmd.data));
	new->next = *stack;
	new->prev = NULL;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
}
/**
 *pall -  prints all the values on the stack
 *
 * @stack: double pointer
 * @cmd: cmd
 */
void pall(stack_t **stack, cmd_t cmd __attribute__((unused)))
{
	stack_t *head = *stack;

	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}
/**
 *pop -  removes the top element of the stack
 *
 *@stack: double pointer
 * @cmd: cmd
 */
void pop(stack_t **stack, cmd_t cmd)
{
	stack_t *temp;

	if (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		if (temp)
			temp->prev = NULL;
		*stack = temp;
	}

	else
	{
		fprintf(stderr, "L%lu: can't pop an empty stack\n", cmd.line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}
/**
 *pint - prints the value at the top of the stack, followed by a new line
 *
 *@stack: double pointer
 *@cmd: cmd
 */
void pint(stack_t **stack, cmd_t cmd)
{
	if (*stack)
		printf("%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%lu: can't pint, stack empty\n", cmd.line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}
/**
 *swap - swaps the top two elements of the stack
 *
 * @stack: double pointer
 * @cmd: cmd
 */
void swap(stack_t **stack, cmd_t cmd)
{
	stack_t *scnd;
	int temp;

	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%lu: can't swap, stack too short\n", cmd.line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	else
	{
		scnd = (*stack)->next;
		temp = (*stack)->n;
		(*stack)->n = scnd->n;
		scnd->n = temp;
	}
}
