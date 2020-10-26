/*
** EPITECH PROJECT, 2020
** factors.c
** File description:
** 
*/
#include <stdlib.h>
#include <stdio.h>
int my_strlen(char const *str);

int my_strtol(char *str, char **endptr);

char *nb_to_str(int nbr);

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
    if (str[i] == 45 || str[i] == 43) {
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

char *factors(char *end_ptr)
{
    int nb = 0;
    int res = 0;
    int fac = 0;
    int i = 0;
    char *s2 = 0;
    char *str = malloc(sizeof(char) * (my_strlen(end_ptr) + 1));

    for (int k = 0; end_ptr[k] < 48 || end_ptr[k] > 57; k++, i++) {
        str[i] = end_ptr[k];
    }
    fac = my_strtol(end_ptr, &end_ptr);
    for (; end_ptr != NULL;) {
        if (end_ptr[0] == '*') {
            nb = my_strtol(end_ptr, &end_ptr);
            fac = fac * nb;
        } else if (end_ptr[0] == '/') {
            nb = my_strtol(end_ptr, &end_ptr);
            fac = fac / nb;
        } else if (end_ptr[0] == '%') {
            nb = my_strtol(end_ptr, &end_ptr); // 20
            fac = fac % nb;
        } else {
            if (fac < 0)
                fac = fac * -1;
            s2 = nb_to_str(fac);
            for (int k = 0; s2[k] != '\0'; k++, i++)
                str[i] = s2[k];
            str[i] = end_ptr[0];
            fac = my_strtol(end_ptr, &end_ptr);
            i++;
        }
    }
    if (fac < 0)
        fac = fac * -1;
    s2 = nb_to_str(fac);
    for (int k = 0; s2[k] != 0; k++, i++) {
        str[i] = s2[k];
    }
    str[i] = '\0';
    return (str); // 41
}