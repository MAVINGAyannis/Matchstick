/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** CPE
*/
#include "main.h"

char **match_taker(char **map, int sizemap, int whatmatch, int whatline)
{
    int whatmatch2 = whatmatch;
    int i = 1;
    int one = whatline;
    int two = sizemap;
    int b = nbstick(sizemap);

    if (whatline < sizemap) {
        while (one != two) {
            b--;
            one++;
        }
    }
    while (map[whatline][b - i] != '|')
        b--;
    while (whatmatch2 != 0) {
        map[whatline][b - i] = ' ';
        whatmatch2 = whatmatch2 - 1;
        b--;
    }
    return (map);
}

int intelligence_turn(char **map, Information *info, int many_stick)
{
    int a = 1;
    int z = 2;
    int o = info->sizemap + 1;
    int whatline = rand_a_b(z, o);
    int whatmatch = rand_a_b(a, info->maxhold + 1);

    whatmatch = optimisation(many_stick, whatmatch, info->maxhold);
    while (enough_match(map, whatmatch, whatline, info->sizemap) == 1) {
        whatline = rand_a_b(z, o);
        whatmatch = rand_a_b(a, info->maxhold);
        optimisation_2(many_stick, whatmatch, info);
    }
    my_printf("AI's turn...\n");
    my_printf("AI removed %d match(es) from line %d\n", whatmatch, whatline);
    map = match_taker(map, info->sizemap, whatmatch, whatline);
    printmap(map, info->sizemap);
    many_stick = many_stick - whatmatch;
    return (many_stick);
}

int player_turn(char **map, Information *info, int many_stick)
{
    Position All;
    Position *all = &All;
    all->whatline = 0;
    all->whatmatch = 0;
    all->whatline = test_line(all->whatline, info->sizemap);
    all->whatmatch = asker_match(all->whatmatch);

    while (respect_max_hold(all->whatmatch, info->maxhold) != 0) {
        cannot_remove(info->maxhold);
        all->whatline = asker_line(all->whatline);
        all->whatmatch = asker_match(all->whatmatch);
    }
    error_least(map, all, info->sizemap);
    error_enough(map, all, info->sizemap);
    many_stick = match_algorithm(all->whatmatch,
    all->whatline, info->sizemap, many_stick);
    map = match_taker(map, info->sizemap, all->whatmatch, all->whatline);
    printmap(map, info->sizemap);
    return (many_stick);
}

int game(char **map, Information *info, int many_stick)
{
    while (many_stick != 0) {
        my_printf("Your turn:\n");
        many_stick = player_turn(map, info, many_stick);
        if (many_stick <= 0) {
            my_printf("You lost, too bad...\n");
            return (2);
        }
        my_printf("\n");
        many_stick = intelligence_turn(map, info, many_stick);
        if (many_stick <= 0) {
            my_printf("I lost... snif... but I'll get you next time!!\n");
            return (1);
        }
        my_printf("\n");
    }
}