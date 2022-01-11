#include "monty.h"

void push(stack_t **stack, cmd_t cmd)
{
		stack_t *temp;

		if (!cmd.if_data || isnan(cmd.data))
		{
			fprintf(stderr, "L%lu: usage: push integer\n", cmd.line_number);
			exit(EXIT_FAILURE);
		}

		if (*stack == NULL)
		{
			*stack = malloc(sizeof(stack_t));
			(*stack)->n = atoi(cmd.data);
			(*stack)->prev = NULL;
			(*stack)->next = NULL;
			return;
		}
		temp = *stack;
		*stack = (*stack)->prev;
		*stack = malloc(sizeof(stack_t));
		(*stack)->n = atoi(cmd.data);
		(*stack)->prev = NULL;
		(*stack)->next = temp;
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