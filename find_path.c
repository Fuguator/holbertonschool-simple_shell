#include "main.h"
/**
 * find_path - func
 * @buffer: buffer
 * @argv: argument vector
 */
void find_path(char *buffer, char **argv)
{
	char *path = getenv("PATH"), *token, error_message[1024];

	if (!path)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
		free(buffer);
		exit(127);
	}
	token = strtok(path, ":");
	while (token)
	{
		snprintf(error_message, sizeof(error_message), "%s/%s", token, argv[0]);
		if (access(error_message, X_OK) == 0)
			_exec(error_message, argv);
		token = strtok(NULL, ":");
	}
}
