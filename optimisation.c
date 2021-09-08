/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** optimisation_2.c
*/
#include "main.h"

int optimisation(int many_stick, int whatmatch, int maxhold)
{
    if (many_stick <= 2)
        whatmatch = 1;
    if (many_stick = 3 && maxhold >= 2)
        whatmatch = 2;
    return (whatmatch);
}

void optimisation_2(int many_stick, int whatmatch, Information *info)
{
    if (many_stick == 2)
        whatmatch = 1;
    if (many_stick == 3 && info->maxhold >= 2)
        whatmatch = 2;
}