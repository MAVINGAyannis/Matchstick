/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** CPE
*/
#include "main.h"

int arguments_error(int argc, char **argv, int sizemap)
{
    int i = 0;

    if (argc != 3 || argc <= 2) {
        my_printf("Usage: ./matchstick 'sizemap' 'maxhold'\n");
        i++;
    }
    if (sizemap > 100 || sizemap <= 1) {
        my_printf("Error: the size of the map ");
        my_printf("should not be bigger than 100.\n");
        i++;
    }
    if (my_getnbr(argv[2]) <= 0)
        i++;
    return (i);
}

int respect_max_hold(int whatmatch, int maxhold)
{
    int i = 0;

    if (whatmatch > maxhold) {
        i++;
    }
    return (i);
}

int enough_match(char **map, int whatmatch, int whatline, int sizemap)
{
    int i = 1;
    int a = 0;
    int z = 0;

    while (map[whatline][i] != '*') {
        if (map[whatline][i] == '|')
            a++;
        i++;
    }
    if (whatmatch > a)
        z++;
    return (z);
}
