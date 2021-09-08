/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** CPE
*/
#include "main.h"

int nbstick(int sizemap)
{
    int stick = 1;

    for (int i = 0; i != sizemap; i++)
        stick += 2;
    return (stick);
}

char *firstandlast(char *map, int stick)
{
    int i;

    for (i = 0; i != stick; i++) {
        map[i] = '*';
    }
    map[stick] = '\n';
    return (map);
}

char *stars(char *map, int stick)
{
    int i;

    for (i = 0; i != stick; i++) {
        map[i] = ' ';
    }
    map[0] = '*';
    map[stick - 1] = '*';
    map[stick] = '\n';
    return (map);
}

char *sticks(char *map, int sizemap, int stick, int v)
{
    int i = 1;
    int space = 1;

    while (i != stick - space) {
        map[i] = '|';
        i++;
    }
    if (v > 0) {
        for (int d = v; d != 0; d--) {
            map[d] = ' ';
            map[stick - d - 1] = ' ';
        }
    }
    return (map);
}

char **mapmaker(int sizemap)
{
    int z = 1;
    int v = 0;
    int i = sizemap;
    int stick = nbstick(sizemap);
    char **map = malloc(sizeof(char *) * (sizemap + 2));

    for (int i = 0; i != sizemap + 1; i++)
        map[i] = malloc(sizeof(char) * (stick + 1));
    map[0] = firstandlast(map[0], stick);
    map[sizemap + 1] = firstandlast(map[0], stick);
    while (i != 0) {
        map[z] = stars(map[z], stick);
        i--;
        z++;
    }
    for (int a = sizemap; a != 0; a--) {
        map[a] = sticks(map[a], sizemap, stick, v);
        v++;
    }
    return (map);
}
