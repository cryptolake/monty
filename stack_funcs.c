#include "monty.h"

/**
* new_node - delete node at index
* @n: data
* Return: new node
**/
stack_t *new_node(int n)
{
    stack_t *new;

    new = malloc(sizeof(stack_t));
    if (!new)
    {
        fprintf(stderr, "Error: malloc failed");
        exit(EXIT_FAILURE);
    }
	new->n = n;

    return (new);
}

/**
* free_stack - free whole stack
* @stack: data
**/
void free_stack(stack_t *stack)
{
    while(stack)
    {
        free(stack);
        stack = stack->next;
    }
}

/**
* delete_node - delete node at index
* @head: head of list
* @index: index of node to delete
* Return: 1 Success, -1 Success
**/
int delete_node(stack_t **head, unsigned int index)
{
	unsigned int i = 0;
	stack_t *p, *temp;

	if (!head || !*head)
		return (-1);
	p = *head;

	while (i != index && p)
	{
		p = p->next;
		i++;
	}

	if (i != index)
		return (-1);

	temp = p->next;
	if (i != 0)
		p->prev->next = temp;
	if (temp)
		temp->prev = p->prev;

	free(p);
	if (i == 0)
		*head = temp;

	return (1);
}