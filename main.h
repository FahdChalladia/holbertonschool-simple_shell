#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

extern char **environ;

void lsh_loop(void);
char **lsh_split_line(char *line);
int lsh_execute(char **args);
char *find_path(char *command);
void free_args(char **args);

#endif
