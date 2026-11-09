#include "main.h"

/**
 * _atoi - Converts a string to an integer
 * @s: Pointer to the string to be converted
 *
 * Return: The converted integer, or 0 if no numbers
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	unsigned int res = 0;
	int started = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
		{
			sign *= -1;
		}
		else if (s[i] == '+')
		{
			/* do nothing, sign remains positive or previous state */
		}
		else if (s[i] >= '0' && s[i] <= '9')
		{
			started = 1;
			res = (res * 10) + (s[i] - '0');
		}
		else if (started == 1)
		{
			break;
		}
		i++;
	}

	return (res * sign);
}
