#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"


/**
 * main - initialize the shell
 *
 * Return: Always 0, EXIT_SUCCESS
 */

void shell_loop(void);

int main(int argc, char *argv[])
{
	//load config files if any
	
	//run command loop
	shell_loop();

	return EXIT_SUCCESS;
}
