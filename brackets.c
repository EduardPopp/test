/*
** EPITECH PROJECT, 2020
** brackets.c
** File description:
** 
*/
#include <stdlib.h>
#include <stdio.h>

int iterator(int res, int count1, char *str)
{
    int count2 = 0;

    for (int i = 0; str[i] != '\0'; i++) { 
        if (str[i] == 40)
            count1++;
        if (str[i] == 41)
            count2++;
    }
    if (count1 == 0) {
        res = summands(str);
        return (res);
    }
    return (count1);
}

char *bracket_term(int i, char *str, char *s1)
{
    int count4 = 0;
    int k = 0;

    for (int z = i; str[z] != 41; z++)
        count4++;
    s1 = malloc(sizeof(char) * (count4));
    s1[k] = '\0';
    

    for (int a = i + 1; str[a] != 41; a++) {
        s1[k] = str[a];
        k++;
    }
    return (s1);
}

char *sumcall(int res, int count1, char *str, char *new)
{
    int count3 = 0;
    int j = 0;
    char *s1 = 0;
    int i = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(')
            count3++;
        if (count3 == count1) {
            s1 = bracket_term(i, str, s1);
            res = summands(s1);
            break;
        } else {
            new[j] = str[i];
        }
        j++;
    }
    if (str[i - 1] == '-' && i == 1)
        res = res * -1;
    return (new);
}

int brackets(char *str)
{
    int res = 0;
    int count1 = 0;
    char *s2 = 0;
    int j = 0;
    char *new = malloc(sizeof(char) * (my_strlen(str) + 1));

    count1 = iterator(res, count1, str);
    new = sumcall(res, count1, str, new);
    s2 = nb_to_str(res);
    for (int x = 0; s2[x] != 0; x++, j++)
        new[j] = s2[x];
    for (int a = a + 1; str[a] != '\0'; a++, j++)
        new[j] = str[a];
    new[j] = '\0';
    res = brackets(new);
    return (res);
}