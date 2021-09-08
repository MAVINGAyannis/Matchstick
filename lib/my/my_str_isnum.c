/*
** EPITECH PROJECT, 2018
** my_str_isnum
** File description:
** my_str_isnum
*/

int my_str_isnum(char const *str)
{
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < 48) || (str[i] > 57))
            j++;
        if (str[i] == ' ')
            j++;
    }
    if (j > 0)
        return (1);
    else
        return (0);
}

int my_str_isnum_with_back(char const *str)
{
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < 48) || (str[i] > 57))
            j++;
        if (str[i] == ' ')
            j++;
    }
    j = j - 2;
    if (j > 0)
        return (1);
    else
        return (0);
}
