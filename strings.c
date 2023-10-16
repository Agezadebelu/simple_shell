#include "shell.h"

/**
 * _strlen - returns string length.
 * Return: returns string length.
 * @s: char type pointer.
 **/

int _strlen(char *s)
{
	int i;

	i = 0;

	while (s[i])
	{
		i++;
	}
	return (i);
}

/**
 *_strcat - joins two strings.
 * @src: string 2 added to string 1.
 * @dest: string 1 take string 2.
 * Return: joined string.
 **/

char *_strcat(char *dest, char *src)
{
	int a, i;

	a = 0;
	i = 0;

	while (dest[a])
	{
		a++;
	}
	while (src[i])
	{
		dest[a] = src[i];
		a++;
		i++;
	}
	return (dest);
}

/**
 * _strcmp - to compares two strings.
 * @s1: string 1.
 * @s2: string 2.
 * Return: integer (-) if s1<s2, 0 if s1=s2 and (+) if s1>s2.
 **/

int _strcmp(char *s1, char *s2)
{
	int i, j;

	i = 0;
	j = 0;

	if (s1[0] == s2[0])
	{
		while (s1[i] == s2[i] && s1[i] && s2[i])
		{
			i++;
		}
	}
	j = (s1[i] - '0') -  (s2[i] - '0');
	return (j);
}

/**
 * _atoi - changes a string to an integer.
 * @str: string to be changed.
 * Return: Always 0.
 */

int _atoi(char *str)
{
	int i, sign;
	double j;

	i = 0;
	j = 0;
	sign = 1;

	while (str[i])
	{
		if (str[i] == '-')
		{
			sign = sign * -1;
		}
		if (str[i] - '0' >= 0 && str[i] - '0' <= 9)
		{
			j = (j * 10) + str[i] - '0';
		}
		else if (j != 0)
		{
			break;
		}
	i++;
	}
	return (j * sign);
}
