#include  "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * shell_loop - read, parse and execute commands
 *
 * Return: Nothing
 */

void shell_loop(void)
{
	char *line;
	char **args;
	int status;

	do {
		printf("$ ");
		line = shell_read_line();
		args = shell_split_line(line);
		status = shell_execute(args);

		free(line);
		free(args);
	} while (status);
}
