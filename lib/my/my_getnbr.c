/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** Return a number sent to the function as a string
*/

#include <stdio.h>

int str_len2(char const *str, int i);

int checkint(char const *str, int i, int symbol);

int int_compare(char const *str, int i, int symbol, int v);

int my_getnbr(char const *str)
{
    int numbr = 0;
    int symbol = 1;
    int i = 0;

    while (str[i] <= 33 || str[i] == '+' || str[i] == '-')
        i++;
    if (str[i - 1] == '-' || str[i - 1] == '+') {
        if (str[i - 1] == '-')
            symbol = -1;
    }
    if (checkint(str, i, symbol) == 0)
        return (0);
    while (str[i] <= '9' && str[i] >= '0') {
        numbr = numbr * 10 + str[i] - '0';
        i++;
    }
    return (numbr * symbol);
}

int int_compare(char const *str, int i, int symbol, int v)
{
    char *tab = "2147483647";
    char *tab2 = "2147483648";
    int count = 0;

    if (symbol == 1) {
        for (v = v ;tab[v] && str[i + v] <= tab[v]; v++) {
            count++;
            if (str[i + v] < tab[v])
                return (1);
        }
    }
    else if (symbol == -1) {
        for ( v = v ; tab2[v] && str[i + v] <= tab2[v]; v++) {
            if (str[i + v] < tab[v])
                return (1);
        }
    }
    if (count == 10)
        return (1);
    return (0);
}

int str_len2(char const *str, int i)
{
    int v = 0;

    while (str[i + v] <= '9' && str[i + v] >= '0') {
        v = v + 1;
    }
    return (v);
}

int checkint(char const *str, int i, int symbol)
{
    int v = 0;

    if (str_len2(str, i) == 10) {
        if (int_compare(str, i, symbol, v) == 0)
            return (0);
    }
    else if (str_len2(str, i) > 10)
        return (0);
    return (1);
}
