#include <stdio.h>
#include <stdlib.h>

/**
 * shell_read_line = reads a line entered by the user
 *
 * Return: Nothing
 */
#define SHELL_BUFFSIZE 1024

char *shell_read_line(void)
{
	int buffsize = SHELL_BUFFSIZE;
	int position = 0;
	char *buffer = malloc(sizeof(char) * buffsize);
	int c;

	if (!buffer)
	{
		fprintf(stderr, "shell: Allocation error\n");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		//read the character
		c = getchar();

		//if we hit EOF, replace it with null character and return
		if (c == EOF || c == '\n')
		{
			buffer[position] = '\0';
			return buffer;
		}
		else{
			buffer[position] = c;
		}
		position++;

		//if we have exceeded the buffer reallocate
		if (position > buffsize)
		{
			buffsize += SHELL_BUFFSIZE;
			buffer = realoc(buffer, buffsize);

			if (!buffer)
			{
				fprintf(stderr, "shell: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}
