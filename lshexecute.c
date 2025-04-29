#include "main.h"

/**
 * lsh_execute - Executes commands
 * @args: Command and arguments
 *
 * Return: 1 to continue shell, 0 to exit
 */
int lsh_execute(char **args)
{
pid_t pid;
int status;
int i;
char *cmd_path;
if (strcmp(args[0], "exit") == 0)
return (0);
if (strcmp(args[0], "env") == 0)
{
for (i = 0; environ[i]; i++)
printf("%s\n", environ[i]);
return (1);
}
cmd_path = find_path(args[0]);
if (!cmd_path)
{
fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
return (1);
}
pid = fork();
if (pid == -1)
{
perror("fork");
free(cmd_path);
return (1);
}
if (pid == 0)
{
if (execve(cmd_path, args, environ) == -1)
{
perror("execve");
free(cmd_path);
exit(EXIT_FAILURE);
}
}
else
{
waitpid(pid, &status, 0);
}
free(cmd_path);
return (1);
}
