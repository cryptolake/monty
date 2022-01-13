#include "monty.h"
/**
 *main - mmm
 *
 *@argc: mmm
 *@argv: mmm
 *Return: mmm
 */
int main(int argc, char const *argv[])
{
	FILE *fd;
	char line[512];
	size_t l_num = 1;
	stack_t *stack = NULL;

if (argc != 2)
	{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");
if (fd == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}

	while (fgets(line, 512, fd))
	{
		parse_line(line, l_num, &stack);
		l_num++;
	}

	fclose(fd);
	free_stack(stack);

	return (EXIT_SUCCESS);
}
