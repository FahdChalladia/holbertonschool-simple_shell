#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * lsh_loop - adds a new node at the beginning of a dlistint_t list
 * @void: pointer to the head of the list
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
