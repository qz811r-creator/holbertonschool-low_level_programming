#include <stdio.h>

/**
 * sum_to_n - Calculates the sum of all integers from 1 to n
 * @n: The upper limit integer
 *
 * Return: The total sum
 */
int sum_to_n(int n)
{
	int i;
	int sum = 0;

	for (i = 1; i <= n; i++)
		sum += i;

	return (sum);
}

int main(void)
{
	printf("%d\n", sum_to_n(10));
	return (0);
}
