#include "holberton.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
/**
 * wildcmp - function that compares two strings Return 0 or 1
 * @s1: the first string to compare
 * @s2: the second string to compare
 * Return: Always 0.
*/
int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
	{
		return (1);
	}

	if (*s1 == *s2 || *s2 == '*')
	{
		if (*s2 == '*')
		{
			if (wildcmp(s1, s2 + 1))
			{
				return (1);
			}
			if (*s1 != '\0' && wildcmp(s1 + 1, s2))
			{
				return (1);
			}
		} else
		{
			return (wildcmp(s1 + 1, s2 + 1));
		}
	}
	return (0);
}
