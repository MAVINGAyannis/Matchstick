/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** CPE
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "lib/my.h"
#include <time.h>

typedef struct Position Position;
struct Position
{
    int whatline;
    int whatmatch;
};

typedef struct Information Information;
struct Information
{
    int sizemap;
    int maxhold;
};

int nbstick (int sizemap);

char *firstandlast(char *map, int stick);

char *thestick(char *map, int stick);

char **mapmaker(int sizemap);

int main(int argc, char *argv[]);

void printmap(char **map, int sizemap);

int player_turn(char **map, Information *info, int many_stick);

int arguments_error(int argc, char **argv, int sizemap);

int respect_max_hold(int whatmatch, int maxhold);

int intelligence_turn(char **map, Information *info, int many_stick);

int enough_match(char **map, int whatmatch, int whatline, int sizemap);

int rand_a_b(int a, int b);

int asker_line(int whatline);

int match_algorithm(int whatmatch, int whatline, int sizemap, int many_stick);

int test_line(int whatline, int sizemap);

int asker_match(int whatmatch);

int game(char **map, Information *info, int many_stick);

void cannot_remove(int maxhold);

int test_buffer(char *buffer);

void error_least(char **map, Position *all, int sizemap);

void error_enough(char **map, Position *all, int sizemap);

void optimisation_2(int many_stick, int whatmatch, Information *info);

int optimisation(int many_stick, int whatmatch, int maxhold);