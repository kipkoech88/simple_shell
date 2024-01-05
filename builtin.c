#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * function declaration for builtin shell commands
 */

int shell_cd(char **args);
int shell_help(char **args);
int shell_exit(char **args);

/*
 * list of builtin commands followed by their corresponding commands
 */

char *builtin_str[] = {
	"cd",
	"help",
	"exit"
};

int (*builtin_fun[]) (char **) = {
	&shell_cd,
	&shell_help,
	&shell_exit
};

int shell_num_builtins()
{
	return sizeof(builtin_str) / sizeof(char *);
}

/*
 * builtin functions implimentations
 */

int shell_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "shell: expected argument to \"cd\"\n");
	}else{
		if (chdir(args[1] != 0))
		{
			perror("shell\n");
		}
	}
	return (1);
}

int shell_help(char **args)
{
	int i;
	printf("Hosea Kipngetich's shell \n");
	printf("Type program's name and arguments, hit enter \n");
	printf("The following are buit in. \n");


	for (i = 0; i < shell_num_builtins(); i++)
	{
		printf(" %s\n", builtin_str[i]);
	}

	printf("Use the man command for information on other commands\n");

	return (1);
}

int shell_exit(char **args)
{
	return (0);
}
