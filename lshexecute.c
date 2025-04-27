@@ -1,12 +1,41 @@
 #include "main.h"
 #include <stdio.h>
 #include <unistd.h>
 #include <stdlib.h>
 #include <string.h>
 
 /**
  * lsh_execute - Executes a parsed command.
  * @args: An array of argument strings, where args[0] is the command.
  * lsh_execute - Executes the command entered by the user
  * @args: Array of strings containing the command and its arguments
  *
  * Return: 1 to continue running the shell, 0 to exit.
  * Return: Returns 0 on success, 1 on error
  */
 int lsh_execute(char **args)
 {
 pid_t pid, wpid;
 int status;
 char *path = args[0];
 
 pid = fork();
 if (pid == -1)
 {
 perror("lsh_execute: fork failed");
 return (1);
 }
 if (pid == 0)
 {
 if (execve(path, args, environ) == -1)
 {
 perror("lsh_execute: execve failed");
 exit(EXIT_FAILURE);
 }
 }
 else
 {
 do {
 wpid = waitpid(pid, &status, WUNTRACED);
 } while (!WIFEXITED(status) && !WIFSIGNALED(status));
 }
 
 return (1);
 }