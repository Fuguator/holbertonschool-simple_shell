#include "main.h"
/**
 * divider - func
 * @buffer: buffer
 * @arr: array
 * Return: arr
 */
char **divider(char *buffer, char **arr)
{
	int i = 0;
	char *token;

	token = strtok(buffer, " \n\t");

	while (token && i < 99)
	{
		arr[i++] = token;
		token = strtok(NULL, " \n\t");
	}
	arr[i++] = NULL;
	return (arr);
}
