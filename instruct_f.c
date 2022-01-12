#include "monty.h"

void push(stack_t **stack, cmd_t cmd)
{
	stack_t *new;

	if (!cmd.if_data || isnan(cmd.data))
	{
		fprintf(stderr, "L%lu: usage: push integer\n", cmd.line_number);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	new->next = *stack;
	new->n = atoi(cmd.data);
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