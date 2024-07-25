#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - multiple format print out
 * 
 * @format: format selector
 * 
 * Return: int on sucess
 */



int _printf(const char *format, ...)
{	
	int i = 0;
	char c;
	char *str;

	va_list args;
    va_start(args, format);


    while (format[i] != '\0')
    {
	    if (format[i] == '%' && format[i + 1] == '%')
	    {
            putchar('%');
            i++;
	    }
	    else if (format[i] == '%' && format[i + 1] == 's')
	    {
		    str = va_arg(args, char *);
		    printf("%s", str);
		    i++;
	    }
	    else if (format[i] == '%' && format[i + 1] == 'c')
	    {
		    c = va_arg(args, int);
		    printf("%c", c);
		    i++;
	    }
	    else if(format[i] == '%' && (format[i + 1] == 'i' ||
			                 format[i + 1] == 'd'))
	    {
		    print_integer(args);
		    i++;
	    }
	    else
	    {
		    putchar(format[i]);
	    }
	    i++;
    }
    va_end(args);
    return 0;
}
