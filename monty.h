#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
		int n;
		struct stack_s *prev;
		struct stack_s *next;
} stack_t;

/**
* struct cmd_s - opcode interface
* @data: data with opcode
* @line_number: line number of the opcode
*
* Description: opcode struct consisting of data
* and line_number
**/
typedef struct cmd_s
{
	char *data;
	size_t line_number;
} cmd_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
		char *opcode;
		void (*f)(stack_t **stack, cmd_t cmd);

} instruction_t;

void parse_line(char *line, size_t line_num, stack_t **stack);
char **strtow(char *str, const char *del);
void free_tow(char **tow);

void push(stack_t **stack, cmd_t cmd);
void pall(stack_t **stack, cmd_t cmd);
void pint(stack_t **stack, cmd_t cmd);
void pop(stack_t **stack, cmd_t cmd);
void swap(stack_t **stack, cmd_t cmd);
void add(stack_t **stack, cmd_t cmd);
void sub(stack_t **stack, cmd_t cmd);
void divide(stack_t **stack, cmd_t cmd);
void mul(stack_t **stack, cmd_t cmd);
void nop(stack_t **stack, cmd_t cmd);
void mod(stack_t **stack, cmd_t cmd);

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_strdup(char *str);
int is_number(char *s);

stack_t *new_node(int n);
void free_stack(stack_t *stack);
int delete_node(stack_t **head, unsigned int index);
size_t stack_len(const stack_t *h);

#endif
