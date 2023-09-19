#include <stdlib.h>
#include <stdio.h>
#include "palindrome.h"
/**
 * is_palindrome - function  integer is a palindrome
 * @n: n = num
 * Return: 0 or 1
*/
int is_palindrome(unsigned long n)
{

int reversed = 0;
int num = n;

	while (n != 0)
{
		reversed = reversed * 10 + n % 10;
		n /= 10;
}
	if (num == reversed)
		return (1);
	else
		return (0);
}
