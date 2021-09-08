/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** CPE
*/
#include "main.h"

void printmap(char **map, int sizemap)
{
    for (int h = 0; h != sizemap + 2; h++)
        my_printf("%s", map[h]);
}

int test_buffer(char *buffer)
{
    if (buffer[0] == '\0' || buffer[0] == '\n')
        return (1234);
    if (buffer[0] == '+' || buffer[0] == '-' || buffer[0] == ' ') {
        if (buffer[1] == '\n' || buffer[1] == '\0')
            return (1234);
    }
    return (0);
}

int main(int argc, char **argv)
{
    char **map;
    if (argc != 3 || my_str_isnum(argv[1]) == 1 || my_str_isnum(argv[2]) == 1)
        return (84);
    Information Info;
    Information *info = &Info;
    info->sizemap = my_getnbr(argv[1]);
    info->maxhold = my_getnbr(argv[2]);
    int many_stick = info->sizemap * info->sizemap;
    int win;

    if (arguments_error(argc, argv, info->sizemap) != 0)
        return (84);
    map = mapmaker(info->sizemap);
    printmap(map, info->sizemap);
    my_printf("\n");
    win = game(map, info, many_stick);
    if (win == 2)
        return (2);
    else if (win == 1)
        return (1);
}
