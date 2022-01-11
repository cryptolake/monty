#include "monty.h"

int main(int argc, char const *argv[])
{
	FILE *fd;
	char *line = NULL;
	size_t len = 0, l_num = 1;
	ssize_t read;

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
	
	while((read = getline(&line, &len, fd)) != -1)
	{
		if (parse_line(line, l_num))
			exit(EXIT_FAILURE);
		l_num++;
	}

	fclose(fd);
	if (line)
		free(line);
	return (EXIT_SUCCESS);
}
