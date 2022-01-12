#include "monty.h"

void push(stack_t **stack, cmd_t cmd)
{
	stack_t *new;

	if (!cmd.if_data || isnan(cmd.data))
	{
		fprintf(stderr, "L%lu: usage: push integer\n", cmd.line_number);
		exit(EXIT_FAILURE);
	}

	new = new_node(atoi(cmd.data));
	new->next = *stack;
	new->prev = NULL;
	if (*stack)
		(*stack) -> prev = new;
	*stack = new;
}

void pall(stack_t **stack, cmd_t cmd __attribute__((unused)))
{
	stack_t *head = *stack;

	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}

void pop(stack_t **stack, cmd_t cmd)
{
	stack_t *temp;

	if (*stack)
	{
		temp =(*stack)->next; 
		free(*stack);
		if (temp)
			temp->prev = NULL;
		*stack = temp;
	}

	else
	{		
		fprintf(stderr, "L%lu: can't pop, empty stack\n", cmd.line_number);
		exit(EXIT_FAILURE);
	}
}

void pint(stack_t **stack, cmd_t cmd)
{
	if (*stack)
		printf("%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%lu: can't pint, stack empty\n", cmd.line_number);
		exit(EXIT_FAILURE);
	}
}
