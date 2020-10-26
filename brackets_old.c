/*
** EPITECH PROJECT, 2020
** brackets.c
** File description:
** 
*/
#include <stdlib.h>
#include <stdio.h>
/*
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
    return (0);
}
*/

int brackets(char *str)
{
    int res = 0;
    int count1 = 0;
    int count2 = 0;
    int count3 = 0; 
    int count4 = 0; 
    int count5 = 0;
    char *s2 = 0;
    int tmp = 0;
    int i = 0;
    int a = 0;
    int k = 0;
    int j = 0;
    char *s1 = 0;
    char *new = malloc(sizeof(char) * (my_strlen(str) + 1));

    for (i = 0; str[i] != '\0'; i++) { // durch den String iterieren
        if (str[i] == 40)
            count1++; // falls zeichen ( count1 erhöhen
        if (str[i] == 41)
            count2++; // falls zeichen ) count2 erhöhen 
    }
    if (count1 == 0) { //für den Fall das keine Klammern auf existieren
        res = summands(str); // sofort res mit dem output von summands beschreiben
        return (res); //res ausgeben
    }
    for (i = 0; str[i] != '\0'; i++) { // durch den String iterieren
        if (str[i] == '(') // erneut die klammer auf zählen
            count3++;   //counter erhöhen
        if (count3 == count1) { //wenn count1 und 3 übereinstimmen
            for (int z = i; str[z] != 41; z++) {
                count4++; //den klammerinhalt zählen
            }
            s1 = malloc(sizeof(char) * (count4));
            for (a = i + 1; str[a] != 41; a++) {
                s1[k] = str[a]; // klammerinhalt in den string füllen
                k++; //k erhöhen
            }
            s1[k] = '\0'; //string terminieren
            res = summands(s1); // res mit ausgabe von summands befüllen
            break; //aus der schleife springen
        } else {
            new[j] = str[i]; //andernfalls den rest in new reinfüllen
        }
        j++; //j erhöhen
    }
    if (str[i - 1] == '-' && i == 1) { // minushandling des results
        res = res * -1;
        j = 0;
    }                       // ab hier muss ich noch selber verstehen
    s2 = nb_to_str(res);  // s2 mit result als string befüllen
    for (int x = 0; s2[x] != 0; x++, j++) {
        new[j] = s2[x]; //new mit s2 inhalt befüllen
    }
    for (a = a + 1; str[a] != '\0'; a++, j++) { //new mit str befüllen
        new[j] = str[a];
    }
    new[j] = '\0'; // new terminieren
    res = brackets(new); //res mit eigenem aufruf beschreiben
    return (res);
}