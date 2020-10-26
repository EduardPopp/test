/*
** EPITECH PROJECT, 2020
** factors.c
** File description:
** 
*/
#include <stdlib.h>
int my_strlen(char const *str);

int my_strtol(char *str, char **endptr);

char *nb_to_str(int nbr);

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