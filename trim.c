#include "main.h"
/**
 * trim - func
 * @string: pointer
 * Return: copy of string without spaces
 */
char *trim(char *string)
{
	char *cpy;
	int count = 0, i = 0, j = 0;
	while (string[j])
		j++;
	cpy = malloc(sizeof(char) * (j + 1));
	if (cpy == NULL)
		return (NULL);
	while (string[i])
	{
		cpy[i] = string[i];
		i++;
	}
	cpy[i] = '\0';
	for (i = 0; cpy[i] != '\0'; i++)
	{
		if (cpy[i] != ' ')
		{
			cpy[count] = cpy[i];
			count++;
		}
	}
	cpy[count] = '\0';
	return (cpy);
}
