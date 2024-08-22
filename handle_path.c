#include "main.h"
/**
 * handle_path - func
 * @buffer: buffer
 * Return: status
 */
int handle_path(char *buffer)
{
	int status = 0;
	pid_t pid = fork();
	char *argv[100];

	if (pid == 0)
	{
		divider(buffer, argv);
		if (!argv[0])
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		if (strcmp(argv[0], "env") == 0)
			print_env(buffer);
		if (strchr(argv[0], '/'))
		{
			if (access(argv[0], X_OK) == 0)
				_exec(argv[0], argv);
		}
		else
			find_path(buffer, argv);
		fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
		free(buffer);
		exit(127);
	}
	else if (pid > 0)
	{
		if (waitpid(pid, &status, 0) == -1)
			perror("Error with waitpid");
		free(buffer);
		if (WIFEXITED(status)) 
			status = WEXITSTATUS(status);
		else
			status = 1;
	}
	else if (pid == -1)
	{
		perror("didn't forked");
		free(buffer);
		exit(EXIT_FAILURE);
	}
	return (status);
}
