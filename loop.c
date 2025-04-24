#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * lsh_loop - The main loop of the shell.
 *
 * Repeats until the user exits (lsh_execute returns 0).
 */
void lsh_loop(void)
{
char *line = NULL;
char **args;
size_t len = 0;
ssize_t read;
int status;
do {
printf("> ");
read = getline(&line, &len, stdin);
if (read == -1)
{
printf("\n");
break;
}
args = lsh_split_line(line);
if (!args[0])
{
free(args);
continue;
}
if (args[1] != NULL)
{
fprintf(stderr, "Error: only one-word commands allowed\n");
free(args);
continue;
}
status = lsh_execute(args);
free(args);
} while (status);
free(line);
}
