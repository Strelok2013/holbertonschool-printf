#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - multiple format print out
 *
 * @format: format selector
 *
 * Return: int on success
 */

int print_integer(va_list args);

int _printf(const char *format, ...)
{
    int i = 0, count = 0;
    char c;
    char *str;
    va_list args;

    if (format == NULL)
        return (-1);


    va_start(args, format);

    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == '\0')
            {

                va_end(args);
                return (-1);
            }
            else if (format[i] == '%')
            {
                write(1, "%", 1);
                count++;
            }
            else if (format[i] == 's')
            {
                str = va_arg(args, char *);
                if (str == NULL)
                    str = "(null)";
                while (*str)
                {
                    write(1, str, 1);
                    str++;
                    count++;
                }
            }
            else if (format[i] == 'c')
            {
                c = va_arg(args, int);
                write(1, &c, 1);
                count++;
            }
            else if (format[i] == 'i' || format[i] == 'd')
            {
                count += print_integer(args);
            }
            else
            {

                write(1, "%", 1);
                write(1, &format[i], 1);
                count += 2;
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
    return count;
}

/**
 * print_integer - prints an integer
 *
 * @args: argument list
 *
 * Return: number of characters printed
 */

int print_integer(va_list args)
{
    int num = va_arg(args, int);
    char buffer[12];
    int i = 0, j, temp;

    if (num == 0)
    {
        write(1, "0", 1);
        return 1;
    }

    if (num < 0)
    {
        write(1, "-", 1);
        num = -num;
        i++;
    }

    temp = num;
    while (temp > 0)
    {
        buffer[i++] = (temp % 10) + '0';
        temp /= 10;
    }

    for (j = i - 1; j >= 0; j--)
    {
        write(1, &buffer[j], 1);
    }

    return i;
}
