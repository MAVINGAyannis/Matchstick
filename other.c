/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** CPE
*/
#include "main.h"

int test_line(int whatline, int sizemap)
{
    whatline = asker_line(whatline);
    while (whatline > sizemap || whatline <= 0) {
        my_printf("Error: this line is out of range\n");
        whatline = asker_line(whatline);
    }
    return (whatline);
}

int match_algorithm(int whatmatch, int whatline, int sizemap, int many_stick)
{
    my_printf("Player removed ");
    my_printf("%d match(es) from line %d\n", whatmatch, whatline);
    many_stick = many_stick - whatmatch;
    return (many_stick);
}

void cannot_remove(int maxhold)
{
    my_printf("Error: you cannot remove ");
    my_printf("more than %d matches per turn\n", maxhold);
}

int asker_line(int whatline)
{
    char *buffer = NULL;
    size_t i = 0;
    int a = 0;

    my_printf("Line: ");
    getline(&buffer, &i, stdin);
    test_buffer(buffer);

    while (my_str_isnum_with_back(buffer) == 1) {
        my_printf("Error: invalid input (positive number expected)\n");
        my_printf("Line: ");
        getline(&buffer, &i, stdin);
    }
    whatline = my_getnbr(buffer);
    return (whatline);
}

int asker_match(int whatmatch)
{
    char *buffer = NULL;
    size_t i = 0;
    int a = 0;

    my_printf("Matches: ");
    getline(&buffer, &i, stdin);
    test_buffer(buffer);
    while (my_str_isnum_with_back(buffer) == 1) {
        my_printf("Error: invalid input (positive number expected)\n");
        my_printf("Matches: ");
        getline(&buffer, &i, stdin);
    }
    whatmatch = my_getnbr(buffer);
    return (whatmatch);
}
