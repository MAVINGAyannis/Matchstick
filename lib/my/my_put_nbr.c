/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** my_put_nbr
*/
#include "../my.h"

void display(int nb, int n, int temp)
{
    int n2;

    n2 = n;
    while (n2 >= 0){
        for (n = n2 ; n > 0 ; n--)
            nb = nb / 10;
        nb = nb % 10;
        my_putchar(nb + '0');
        nb = temp;
        n2 = n2 - 1;
    }
}

int my_put_nbr(int nb)
{
    int n = 0;
    int temp;

    if (nb == -2147483648){
        my_putchar('-');
        my_putchar('2');
        nb = 147483648;
    }
    else if (nb < 0){
        my_putchar('-');
        nb = -nb;
    }
    temp = nb;
    while (nb > 9){
        nb = nb / 10;
        n++;
    }
    nb = temp;
    display(nb, n, temp);
    return (0);
}
