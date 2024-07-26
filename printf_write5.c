#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

int handle_percent(const char *format, int *i, va_list args, int *count);
int handle_string(va_list args, int *count);
int handle_char(va_list args, int *count);

/**
 * _printf - multiple format print out
 * @format: format selector
 *
 * Return: int on success
 */
int _printf(const char *format, ...)
{
	int i, count;
	va_list args;

	i = 0;
	count = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (handle_percent(format, &i, args, &count) == -1)
			{
				va_end(args);
				return (-1);
			}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

/**
 * handle_percent - handles % format specifiers
 * @format: format string
 * @i: pointer to current index
 * @args: va_list of arguments
 * @count: pointer to character count
 *
 * Return: 0 on success, -1 on failure
 */
int handle_percent(const char *format, int *i, va_list args, int *count)
{
	(*i)++;
	if (format[*i] == '\0')
		return (-1);
	else if (format[*i] == '%')
	{
		write(1, "%", 1);
		(*count)++;
	}
	else if (format[*i] == 's')
	{
		handle_string(args, count);
	}
	else if (format[*i] == 'c')
	{
		handle_char(args, count);
	}
	else if (format[*i] == 'i' || format[*i] == 'd')
	{
		*count += print_integer(args);
	}
	else
	{
		write(1, "%", 1);
		write(1, &format[*i], 1);
		*count += 2;
	}
	return (0);
}

/**
 * handle_string - handles string format specifier
 * @args: va_list of arguments
 * @count: pointer to character count
 *
 * Return: 0 on success
 */
int handle_string(va_list args, int *count)
{
	char *str;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
	while (*str)
	{
		write(1, str, 1);
		str++;
		(*count)++;
	}
	return (0);
}

/**
 * handle_char - handles char format specifier
 * @args: va_list of arguments
 * @count: pointer to character count
 *
 * Return: 0 on success
 */
int handle_char(va_list args, int *count)
{
	char c;

	c = va_arg(args, int);
	write(1, &c, 1);
	(*count)++;
	return (0);
}
