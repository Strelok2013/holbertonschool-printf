#include "main.h"

unsigned int get_number_of_digits(int num)
{
	int number = num;
	unsigned int count = 0;

	if(number < 0)
		number *= -1;
	while (number)
	{
		number /= 10;
		count++;
	}
	return (count);
}

/**
 * reverse_elem - reverse number
 *@p: pointer
 *@size: block size of number
 *
 * Return: none
 */

void reverse_elem(int *p, unsigned int size)
{
	unsigned int i = 0;
	int tmp = 0;

	while (i < (size / 2))
	{
		tmp = p[i];
		p[i] = p[size - i - 1];
		p[size - i - 1] = tmp;
		i++;
	}
}

/**
 * get_digits - read the digits
 *@num: number to be read
 *
 * Return: integer value
 */

int *get_digits(int num)
{
	int *p;
	int number = num, count = 0;
	unsigned int size = 0;

	if (num < 0)
		number *= -1;
	while (number)
	{
		number /= 10;
		count++;
		size++;
	}
	p = malloc(size * sizeof(int));
	if (!p)
	{
		free(p);
		exit(1);
	}
	number = num;
	count = 0;
	if (num < 0)
		number *= -1;
	while (number)
	{
		p[count] = number % 10;
		printf("p[%d]: %d\n", count, p[count]);
		number /= 10;
		count++;
	}
	reverse_elem(p, size);
	return (p);
}

/**
 * print_integer - writes an integer to the output stream.
 * @arg: argument passed in from the format string.
 *
 * Return: The number of bytes written.
 */

unsigned int print_integer(va_list arg)
{
	int number = va_arg(arg, int), i = 0;
	char c = 0;
	unsigned int bytes = 0;
	int *digits = get_digits(number);
	unsigned int size = get_number_of_digits(number);

	if (number < 0)
	{
		c = 45;
		bytes += write(1, &c, 1);
	}
	while (i < size)
	{
		c = digits[i] + '0';
		bytes += write(1, &c, 1);
		i++;
	}
	free(digits);
	return (bytes);
}
