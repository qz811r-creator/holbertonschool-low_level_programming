#include <stdio.h>

/**
 * main - entry point for the simple calculator program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int choice;

	do {
		printf("Simple Calculator\n");
		printf("1) Add\n");
		printf("2) Subtract\n");
		printf("3) Multiply\n");
		printf("4) Divide\n");
		printf("0) Quit\n");
		printf("Choice: ");

		if (scanf("%d", &choice) != 1)
		{
			printf("Invalid input\n");
			break;
		}

		if (choice == 0)
		{
			printf("Bye!\n");
			break;
		}
	} while (choice != 0);

	return (0);
}
