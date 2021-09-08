/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** other_2.c
*/
#include "main.h"

int rand_a_b(int a, int b)
{
    int i = rand() % (b - a) + a;
    return (i);
}