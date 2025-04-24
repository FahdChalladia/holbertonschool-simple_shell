#ifndef MAIN_H
#define MAIN_H


void lsh_loop(void);
char **lsh_split_line(char *line);
int lsh_execute(char **args);

#endif
