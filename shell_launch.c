#include <unistd.h>
#include <stdio.h>
#include "main.h"
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

/**
 * shell_launch - launches the shell instance and execute commands
 * @args: arguments 
 * Return: 1
 */

int shell_launch(char **args)
{
	pid_t pid, wpid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		//child process
		if ( execvp(args[0], args) == -1)
		{
			perror("shell\n");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		//Error creating child process/forking
		perror("Shell");
	}
	else
	{
		do{
			//parent process
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}
