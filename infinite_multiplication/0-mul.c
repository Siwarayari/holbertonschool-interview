#include "holberton.h"
/**
 * str_length - returns the length of the string
 * @n: string
 * Return: count
*/
int str_length(char *n)
{
	int count;

	for (count = 0; n[count] != '\0'; count++)
	;

	return (count);
}
/**
 * _puts - prints a string
 * @str: string
 * Return: void
*/
void _puts(char *str)
{
	if (*str != '\0')
	{
		_putchar(*str);
		puts(str + 1);
	}
}
/**
 * _isdigit - function to check if a digit or not
 * @c: string
 * Return: dig
*/
int _isdigit(char *c)
{
	int i, dig = 1;

	for (i = 0; c[i] && dig; i++)
	{
		if (c[i] < '0' || c[i] > '9')
			dig = 0;
	}
	return (dig);
}
/**
 * mul - program that multiplies two positive numbers
 * @num1: number 1 to multiply
 * @num2: number 2 to multiply
 * Return: result
*/
char *mul(char *num1, char *num2)
{
	int len1 = str_length(num1);
	int len2 = str_length(num2);
	int total = (len1 + len2);
	char *result = NULL;
	int i;
	int j;
	int carry;
	int car;

	result = malloc(sizeof(char) * len1 + len2);

	if (!result)
	{
		_puts("Error");
		exit(98);
	}

	for (i = 0; i < total; i++)
		result[i] = '0';

	for (i = len1 - 1 ; i >= 0 ; i--)
	{
		carry = 0;
		car = 0;

		for (j = (len2 - 1); j >= 0 ; j--)
		{
			carry += (num1[i] - '0') * (num2[j] - '0');
			carry += result[j + i + 1] - '0';
			result[j + i + 1] = (carry % 10) + '0';
			car = (carry /= 10);
		}
		if (car)
			result[i + j + 1] = car + '0';
	}
	return (result);
	free(result);
}
/**
 * main - main function
 * @argc: argc
 * @argv: argv
 * Return: result
*/
int main(int argc, char *argv[])
{
	char *number1 = argv[1];
	char *number2 = argv[2];
	char *result = NULL;

	if (argc != 3 || !_isdigit(number1) || !_isdigit(number2))
	{
		_puts("Error");
		exit(98);
	}

	if (*number1 == '0' || *number2 == '0')
	{
		_puts("0");
		return (0);
	}

	result = mul(argv[1], argv[2]);

	if (result[0] == '0')
		_puts(result + 1);
	else
		_puts(result);
	free(result);
	return (0);
}
