#include <stdio.h>

/**
 * main - entry point for the simple calculator program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int choice;
	double a, b;

	while (1)
	{
		printf("Simple Calculator\n");
		printf("1) Add\n");
		printf("2) Subtract\n");
		printf("3) Multiply\n");
		printf("4) Divide\n");
		printf("0) Quit\n");
		printf("Choice: ");

		if (scanf("%d", &choice) != 1)
		{
			printf("Invalid choice\n");
			break;
		}
		if (choice == 0)
		{
			printf("Bye!\n");
			break;
		}
		else if (choice >= 1 && choice <= 4)
		{
			printf("A: ");
			scanf("%lf", &a);
			printf("B: ");
			scanf("%lf", &b);
			if (choice == 1)
				printf("Result: %g\n", a + b);
			else if (choice == 2)
				printf("Result: %g\n", a - b);
			else if (choice == 3)
				printf("Result: %g\n", a * b);
			else if (choice == 4)
			{
				if (b == 0)
					printf("Error: division by zero\n");
				else
					printf("Result: %g\n", a / b);
			}
		}
		else
			printf("Invalid choice\n");
	}
	return (0);
}
