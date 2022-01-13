#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (!data || is_number(data))
	{
		fprintf(stderr, "L%du: usage: push integer\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	new = new_node(atoi(data));
	new->next = *stack;
	new->prev = NULL;
	if (*stack)
		(*stack) -> prev = new;
	*stack = new;
}

void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *head = *stack;

	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}

void pop(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%du: can't pop, empty stack\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack)
		printf("%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%du: can't pint, stack empty\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *scnd;
	int temp;

	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%du: can't swap, stack too short\n", line_number);
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


void add(stack_t **stack, unsigned int line_number)
{
	int sum;
	stack_t *new;

	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%du: can't add, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	new = (*stack)->next;

	sum = (*stack)->n;
	sum += (*stack)->next->n;

	delete_node(stack, 0);
	new->n = sum;
}

void nop(stack_t **stack __attribute__((unused)), unsigned int line_number __attribute__((unused)))
{
}
