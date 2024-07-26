#include "main.h"

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

int *get_digits(int num)
{
	int *p;
	int number = num, count = 0;
	unsigned int size = 0;

	if(num < 0)
		number *= -1;
	while (number)
	{
		number /= 10;
		count++;
		size++;
	}
	p = malloc(count * sizeof(int));
	if(!p)
	{
		free(p);
		exit(1);
	}
	number = num;
	if(num < 0)
		number *= -1;
	while (number)
	{
		p[count] = number % 10;
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

	if (number < 0)
	{
		c = 45;
		bytes += write(1, &c, 1);
	}
	while (digits[i])
	{
		c = digits[i] + '0';
		bytes += write(1, &c, 1);
		i++;
	}
	free(digits);
	return (bytes);
}
