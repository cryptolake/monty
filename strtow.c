#include "monty.h"

/**
 * strtow - split a string into tokens by delimeter
 *
 * @str: string
 * @del: delimeter
 *
 * Return: array of strings of tokens
 **/
char **strtow(char *str, const char *del)
{
char *token;
char **words = NULL;
int x = 0;

token = strtok(str, del);
if (!token)
return (NULL);
while (token)
	{
words = _realloc(words, sizeof(char *) * x, sizeof(char *) * (x + 1));
words[x++] = _strdup(token);
		token = strtok(NULL, del);
	}
words = _realloc(words, sizeof(char *) * x, sizeof(char *) * (x + 1));
words[x] = NULL;
	return (words);
}

/**
 * free_tow - free the array
 * @tow: array
 *
 **/
void free_tow(char **tow)
{
	int i = 0;

	while (tow[i])
		free(tow[i++]);
	free(tow);
}
