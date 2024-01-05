#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * main - maine shell program
 * @argc: argument count
 * @argv: argument array
 * @env: environment variable
 * Return: Always success (0);
 */

int main(int argc, char **argv, char **env)
{
	/* load config files if any*/

	/* run the shell loop */
	hsh_loop();

	return (0);
}
