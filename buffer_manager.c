#include "main.h"

/**
 * write_to_buffer - adds a character to the local buffer
 * @c: char to add
 * @buffer: the buffer array
 * @index: current position in the buffer (pointer to int)
 *
 * Return: 1 (the number of characters added to the buffer)
 */
int write_to_buffer(char c, char *buffer, int *index)
{
	if (*index >= BUF_SIZE)
	{
		write(1, buffer, *index);
		*index = 0;
	}

	buffer[*index] = c;
	(*index)++;

	return (1);
}
