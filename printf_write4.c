#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"


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
            if (format[i + 1] == '\0')
            {

                write(1, "%", 1);
                count++;
                break;
            }
            else if (format[i + 1] == '%')
            {
                write(1, "%", 1);
                count++;
                i++;
            }
            else if (format[i + 1] == 's')
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
                i++;
            }
            else if (format[i + 1] == 'c')
            {
                c = va_arg(args, int);
                write(1, &c, 1);
                count++;
                i++;
            }
            else if (format[i + 1] == 'i' || format[i + 1] == 'd')
            {
                count += print_integer(args);
                i++;
            }
            else
            {

                write(1, "%", 1);
                count++;
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
