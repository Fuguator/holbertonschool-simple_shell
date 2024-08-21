#include "main.h"

int main(void)
{
	char *buf, *token;
	size_t linelen, i;
	pid_t child;
	int status;
	char *argv[100];
	char *trimmed;

	while (1)
	{
		i = 0;
		buf = NULL;
		if (getline(&buf, &linelen, stdin) == -1)
		{
			free(buf);
			exit(0);
		}
		trimmed = trim(buf);
		if (trimmed[0] == '\n')
		{
			free(trimmed);
			free(buf);
			continue;
		}
		free(trimmed);
		token = strtok(buf, " \n");
		while(token)
		{
			argv[i] = token;
			token = strtok(NULL, " \n");
			i++;
		}
		argv[i] = NULL;
		if (strcmp(argv[i - 1], "exit") == 0)
		{
			free(buf);
			if (i == 1)
				exit(0);
			else
				exit(2);
		}
		child = fork();
		if (child == -1)
		{
			free(buf);
			perror("Fork failed");
			exit(EXIT_FAILURE);
		}
		else if (child == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				free(buf);
				perror("we found error");
				exit(0);
			}
		}
		else
		{
			if (wait(&status) == -1)
				free(buf), perror("wait has failed"), exit(0);
		}
		free(buf);
	}

	return (0);
}
