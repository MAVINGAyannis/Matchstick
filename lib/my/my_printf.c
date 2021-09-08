/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** my_printf
*/
#include <stdarg.h>
#include <stdio.h>
#include "../my.h"

void whatflag(char f, va_list ap)
{
    if (f == 'd' || f == 'i')
        my_put_nbr(va_arg(ap, int));
    if (f == 'c')
        my_putchar(va_arg(ap, int));
    if (f == 's')
        my_putstr(va_arg(ap, char *));
    if (f == 'p')
        my_put_nbr(va_arg(ap, int));
}

int my_printf(char *f, ...)
{
    va_list ap;
    va_start(ap, f);

    int i = 0;

    for (int i = 0; f[i] != '\0'; i++) {
        if (f[i] != '%')
            my_putchar(f[i]);
        if (f[i] == '%') {
            whatflag(f[i + 1], ap);
            i++;
        }
    }
    va_end(ap);
}
