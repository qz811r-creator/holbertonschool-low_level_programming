#include "main.h"

/**
 * _strcpy - Copies the string pointed to by src, including
 *           the terminating null byte, to dest
 * @dest: Pointer to the buffer where the string is copied
 * @src: Pointer to the string to be copied
 *
 * Return: The pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}
