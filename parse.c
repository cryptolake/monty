#include "monty.h"

int parse_line(char *line, size_t line_num)
{
	char *delims = " \t\r\n";
	char **p_line;
	cmd_t cmd;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	instruction_t *instruct_p = instructions;
	stack_t *stack = NULL;
	p_line = strtow(line, delims);
	/* printf("%s %s\n", p_line[0], p_line[1]); */ 
	if (p_line)
	{
		while (instruct_p->opcode && strcmp(instruct_p->opcode, p_line[0]) != 0)
			instruct_p++;
			
		if (instruct_p->opcode)
		{
			if (p_line[1] != NULL)
			{
				cmd.if_data = 1;
				cmd.data = p_line[1];
			}

			else
			{
				cmd.if_data = 0;
				cmd.data = NULL;
			}
			cmd.line_number = line_num;
			instruct_p->f(&stack, cmd);
		}
		else
		{
			fprintf(stderr, "L%lu: unknown instruction %s", line_num, p_line[0]);
			exit(EXIT_FAILURE);
		}
	}
	free_tow(p_line);

	return (0);
}