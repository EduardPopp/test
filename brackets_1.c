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

int count_brackets(char *str, int count1);

int last_res(char *str, int res, int count1);

int find_last_bracket(char *str, int count1)
{
    int count3 = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(')
            count3++;
        if (count3 == count1)
            return (i);
    }
    return (0);
}

int count_content(char *str, int a, int count1)
{
    count1 = 0;
    for (; str[a] != 41; a++) {
        count1++;
    }
    return (count1);
}

char *build_s1(char *str, char *s1, int a, int count1)
{
    int k = 0;

    s1 = malloc(sizeof(char) * (count1));
    for (; str[a] != '\0'; a++) {
        for (; str[a] != 41; a++, k++) {
            s1[k] = str[a];
        }
        s1[k + 1] = '\0';
        break;
    }
    return (s1);
}

char *build_new(char *str, int res, int k, int count1)
{
    int j = 0;
    int i = 0;
    char *s2 = 0;
    char *new = malloc(sizeof(char) * (my_strlen(str) + 1));

    for (; i < k - 1; i++, j++) {
        new[j] = str[i];
    }
    printf("k: %d\n", k);
    if (str[k - 2] == '-') {
        printf("delete minus\n");
        res = res * -1;
        j--;
    }
    s2 = nb_to_str(res);
    for (int x = 0; s2[x] != 0; x++, j++) {
        new[j] = s2[x];
    }
    for (k = (k + count1 + 1); str[k] != '\0'; k++, j++) {
        new[j] = str[k];
    }
    new[j] = '\0';
    printf("new: %s\n", new);
    return (new);
}

int brackets(char *str, int a, int k)
{
    int res = 0;
    int count1 = 0;
    char *s1 = 0;
    char *new;

    printf("str1: %s\n", str);
    count1 = count_brackets(str, count1);
    res = last_res(str, res, count1);
    if (res != 0) 
        return (res);
    a = find_last_bracket(str, count1) + 1;
    k = a;
    for (; str[a] != '\0'; a++) {
        count1 = count_content(str, a, count1);
        s1 = build_s1(str, s1, a, count1);
        res = summands(s1);
        break;
    }
    new = build_new(str, res, k, count1);
    res = brackets(new, a, k);
    return (res);
}