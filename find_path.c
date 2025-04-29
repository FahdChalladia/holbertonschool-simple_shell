#include "main.h"

/**
 * find_path - Search command in PATH
 * @command: Command to find
 *
 * Return: Full path or NULL if not found
 */
char *find_path(char *command)
{
	char *path = getenv("PATH");
	char *token, *full_path;
	struct stat st;

	if (!path || strchr(command, '/'))
	{
		if (stat(command, &st) == 0)
			return (strdup(command));
		return (NULL);
	}

	token = strtok(strdup(path), ":");
	while (token)
	{
		full_path = malloc(strlen(token) + strlen(command) + 2);
		if (!full_path)
			return (NULL);

		sprintf(full_path, "%s/%s", token, command);
		if (stat(full_path, &st) == 0)
			return (full_path);

		free(full_path);
		token = strtok(NULL, ":");
	}
	return (NULL);
}
