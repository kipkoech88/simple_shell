#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * shell_execute - executes shell commands
 *
 * @args: arguments to be executed
 *
 */

int shell_execute(char **args)
{
	int i;

	if (args[0] == NULL)
	{
		//an empty command was entered
		return (1);
	}

	for (i = 0; i < shell_num_builtins(); i++)
	{
		if (strcmp(args[0], builtin_str[i]) == 0)
		{
			return (*builtin_fun[i])(args);
		}
	}

	return shell_launch(args);
}
