#include "main.h"
/**
 * print_env - func
 * @buffer: var
 */
void print_env(char *buffer)
{
	int i = 0;
	char **env = environ;

	for (; *(env + i); i++)
		printf("%s\n", *(env + i));

	free(buffer);
	exit(EXIT_SUCCESS);
}
