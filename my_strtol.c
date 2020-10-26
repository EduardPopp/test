/*
** EPITECH PROJECT, 2020
** my_strtol
** File description:
** .
*/

#include <stdlib.h>
#include <stdio.h>

int my_strlen(char const *str);

int my_getnbr(char const *str);

int number(char **str_ptr)
{
    int nb = 0;

    nb = my_getnbr(*str_ptr);
    return (nb);
}

int manage_i(int i, char *str)
{
    if (i > 0) {
        i--;
    }
    for (; str[i] == 45 || str[i] == 43;) {
        i++;
    }
    return (i);
}

int my_strtol(char *str, char **endptr)
{
    int nb = 0;
    int i = 0;

    for (; i < my_strlen(str); i++) {
        if ((str[i] >= '0' && str[i] <= '9') || str[i] == 45) {
            str = &str[i];
            nb = number(&str);
            break;
        }
    }
    i = manage_i(i, str);
    for (; i < my_strlen(str); i++) {
        if (str[i] < '0' || str[i] > '9') {
            *endptr = &str[i];
            break;
        } else if (i == my_strlen(str) - 1) {
            *endptr = NULL;
        }
    }
    return (nb);
}