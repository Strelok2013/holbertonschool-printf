#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include <sys/types.h>

#include <stdarg.h>

int _printf(const char *format, ...);
unsigned int print_integer(va_list arg);
#endif
