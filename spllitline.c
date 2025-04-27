#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * lsh_split_line - Splits a line into tokens (commands and arguments)
 * @line: The input string (command line)
 *
 * Return: An array of tokens (commands and arguments)
 */
char **lsh_split_line(char *line)
{
int bufsize = 64, position = 0;
char **tokens = malloc(bufsize * sizeof(char *));
char *token;

if (!tokens)
{
perror("split_line: allocation error");
exit(EXIT_FAILURE);
}

token = strtok(line, " \t\r\n\a");
while (token != NULL)
{
tokens[position] = token;
position++;

if (position >= bufsize)
{
bufsize += 64;
tokens = realloc(tokens, bufsize *sizeof(char *));
if (!tokens)
{
perror("split_line: allocation error");
exit(EXIT_FAILURE);
}
}

token = strtok(NULL, " \t\r\n\a");
}

tokens[position] = NULL;
return (tokens);
}
