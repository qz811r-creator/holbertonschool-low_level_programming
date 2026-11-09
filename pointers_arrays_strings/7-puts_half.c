#include "main.h"

/**
 * puts_half - Prints the second half of a string, followed by a new line
 * @str: Pointer to the string
 *
 * Return: void
 */
void puts_half(char *str)
{
	int len = 0;
	int i, n;

	while (str[len] != '\0')
	{
		len++;
	}

	if (len % 2 == 0)
	{
		i = len / 2;
	}
	else
	{
		n = (len + 1) / 2;
		i = len - n;
	}

	while (i < len)
	{
		_putchar(str[i]);
		i++;
	}
	_putchar('\n');
}
