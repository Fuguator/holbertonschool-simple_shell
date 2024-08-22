#include "main.h"
/**
 * main - func
 * Return: status
 */
int main(void)
{
	char *storage = NULL;
	int status = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "Simple Shell$ ", 14);
		storage = _getline();
		if (!storage)
			break;
		if (strcmp(storage, "exit") == 0)
		{
			free(storage);
			exit(0);
		}
		status = handle_path(storage);
		if (status == 2)
			exit(2);
	}
	return (status);
}

