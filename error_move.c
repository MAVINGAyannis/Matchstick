/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** error_move.c
*/
#include "main.h"

void error_least(char **map, Position *all, int sizemap)
{
    while (all->whatmatch <= 0) {
        my_printf("Error: you have to remove at least one match\n");
        all->whatline = asker_line(all->whatline);
        all->whatmatch = asker_match(all->whatmatch);
        error_enough(map, all, sizemap);
    }
}

void error_enough(char **map, Position *all, int sizemap)
{
    while (enough_match(map, all->whatmatch, all->whatline, sizemap) != 0) {
        my_printf("Error: not enough matches on this line\n");
        all->whatline = asker_line(all->whatline);
        all->whatmatch = asker_match(all->whatmatch);
        error_least(map, all, sizemap);
    }
}