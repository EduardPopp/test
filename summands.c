/*
** EPITECH PROJECT, 2020
** summands.c
** File description:
** 
*/
#include <stdlib.h>

int summands(char *str)
{
    int nb = 0;
    int res = 0;
    int sum = 0;
    char *end_ptr;

    end_ptr = factors(str);
    sum = my_strtol(end_ptr, &end_ptr);
    for (int i = 0; end_ptr != NULL;) {
        nb = my_strtol(end_ptr, &end_ptr);
        sum = sum + nb;
    }
    return (sum);
}