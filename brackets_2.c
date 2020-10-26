/*
** EPITECH PROJECT, 2020
** .
** File description:
** .
*/

#include <stdlib.h>
#include <stdio.h>

int my_strlen(char const *str);

int summands(char *str);

char *nb_to_str(int nbr);

int count_brackets(char *str, int count1)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 40)
            count1++;
    }
    return (count1);
}

int last_res(char *str, int res, int count1)
{
    if (count1 == 0) {
        res = summands(str);
        return (res);
    }
    return (0);
}