#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * shell_split_line - gets tokens from string
 *
 * @line: line to be parsed
 *
 * Return: tokens
 */

#define SHELL_TOK_BUFSIZE 64
#define SHELL_TOK_DELIM " \t\r\n\a"

char **shell_split_line(char *line)
{
	int bufsize = SHELL_TOK_BUFSIZE, position = 0;
	char **tokens = malloc(busize * sizeof(char));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "shell: Allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, SHELL_TOK_DELIM);

	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += SHELL_TOK_BUFSIZE;
			tokens = realloc(tokens, bufsize * sizeof(char*));

			if (!tokens)
			{
				fprintf(stderr, "shell: Allocation error\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, SHELL_TOK_DELIM);
	}
	tokens[position] = NULL;

	return tokens;
}
