#include "monty.h"

/**
 * _realloc - reallocates a memory block
 * @ptr: old mem
 * @old_size: old_size
 * @new_size: new_size
 *
 * Return: new mem
 **/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *nptr;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		nptr = malloc(new_size);
		return (nptr);
	}

	if (!new_size)
	{
		free(ptr);
		return (NULL);
	}

	nptr = malloc(old_size + (new_size - old_size));

	memcpy(nptr, ptr, old_size);

	free(ptr);

	return (nptr);
}


/**
* isnan - check if string a number or not
*
* @s: s
*
* Return: 1 not number, 0 a number
**/
int isnan(char *s)
{
    int i = 0;

    while (s[i])
    {
        if (s[i] < '0' || s[i] > '9')
		    return (1);
        i++;
    }
    return (0);
}