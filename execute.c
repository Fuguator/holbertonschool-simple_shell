#include "main.h"
/**
 * _exec - func
 * @buffer: buffer
 * @arr: arr
 */
void _exec(char *buffer, char **arr)
{
	if (execve(buffer, arr, environ) == -1)
	{
		perror("Error");
		free(buffer);
		exit(EXIT_FAILURE);
	}
}
