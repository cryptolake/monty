#include "monty.h"

void parse_line(char *line, size_t line_num, stack_t **stack)
{
	char *delims = " \t\r\n";
	char **p_line;
	cmd_t cmd;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	instruction_t *instruct_p = instructions;

	p_line = strtow(line, delims);

	if (p_line)
	{
		while (instruct_p->opcode && strcmp(instruct_p->opcode, p_line[0]) != 0)
			instruct_p++;
			
		if (instruct_p->opcode)
		{
			/* printf("%s\n", p_line[1]); */
			if (p_line[1] != NULL)
				cmd.data = p_line[1];
			else
				cmd.data = NULL;
			cmd.line_number = line_num;
			instruct_p->f(stack, cmd);
		}
		else
		{
			fprintf(stderr, "L%lu: unknown instruction %s\n", line_num, p_line[0]);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
	}
	if (p_line)
		free_tow(p_line);

}
