#include "main.h"
/**
 * _getline - func
 * Return: storage
 */
char *_getline(void)
{
	char *storage = NULL;
	size_t len = 0;
	int size;

	size = getline(&storage, &len, stdin);

	if (size == -1)
	{
		free(storage);
		return (NULL);
	}
	if (storage[size - 1] == '\n')
		storage[size - 1] = '\0';
	return (storage);
}
