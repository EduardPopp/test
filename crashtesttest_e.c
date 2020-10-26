/*
** EPITECH PROJECT, 2020
** my_strtol.c
** File description:
** .
*/

#include <stdlib.h>
#include <stdio.h>

void my_putchar(char c);

int my_getnbr(char const *str);

int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src);

int my_put_nbr(int count);

char *my_revstr(char *str);

char *nb_to_str(int nbr);

int brackets(char *str, int a, int k);

int my_strtol(char *str, char **endptr);

char *factors(char *end_ptr)
{
    int nb = 0;
    int res = 0;
    int fac = 0;
    int i = 0;
    char *s2 = 0;
    char *str = malloc(sizeof(char) * (my_strlen(end_ptr) + 1));

/*    for (int k = 0; end_ptr[k] < 48 || end_ptr[k] > 57; k++, i++) {
        str[i] = end_ptr[k];
    }
*/    printf("str: %s\n", end_ptr);
    fac = my_strtol(end_ptr, &end_ptr);  //aufruf der function string to long um den factor zu bekommen. 
    printf("endptr2: %s\n", end_ptr);
    printf("fac: %d\n", fac);
    for (; end_ptr != NULL;) {     //solange der Endpointer im String nicht NULL also das Ende erreicht
        if (end_ptr[0] == '*') {  // Wenn der Endpointer am 0. index * ist
            //printf("mal\n");
            nb = my_strtol(end_ptr, &end_ptr);  //rufe erneut string to long auf um die zahl zu bekommen
            printf("nb: %d\n", nb);
            fac = fac * nb;   //führe Multiplikation aus
            //if (fac == 0)
             //   fac = +0;
            printf("fac4: %d\n", fac);
        } else if (end_ptr[0] == '/') {  //andernfalls wenn Endpointer an seiner 0. Index / ist
            nb = my_strtol(end_ptr, &end_ptr);  //hole Nummer aus String mittels Strtol
            fac = fac / nb;    //führe Division aus
            printf("fac3: %d\n", fac);
        } else if (end_ptr[0] == '%') {   //andernfalls wenn Endpointer an 0. Index %
            nb = my_strtol(end_ptr, &end_ptr);  //hole die Operanden aus dem String mittels Strtol
            fac = fac % nb;  // führe operation modulo aus
        } else {   // für alle anderen Zeichen die keine operatoren darstellen 
//            if (fac < 0)
//                fac = fac * -1;
            s2 = nb_to_str(fac);   // packe nummer in String s2
            for (int k = 0; s2[k] != '\0'; k++, i++) { //solange string 2 nicht am \0
                str[i] = s2[k];  //inhalt in str reinschreiben
            }
//            str[i] = end_ptr[0];
            fac = my_strtol(end_ptr, &end_ptr); // factor 2 aus dem String holen. 
            printf("fac2: %d\n", fac);
//            i++;
        }
    }
//    if (fac < 0)
//        fac = fac * -1;
    s2 = nb_to_str(fac); // die restliche Zahl in den String packen
    for (int k = 0; s2[k] != 0; k++, i++) {  //anmerkung für später: muss da nicht \0? 
        str[i] = s2[k]; // inhalt von s2 in str schreiben.
    }
    str[i] = '\0'; // str abschließen
    printf("endendstr: %s\n", str);
    return (str); //den str aus der Funktion returnen
}

int summands(char *str)
{
    int nb = 0;
    int res = 0;
    int sum = 0;
    char *end_ptr;

    end_ptr = factors(str); // aufruf der factors function und den returnstring in end_ptr packen
    printf("endptr: %s\n", end_ptr);
    sum = my_strtol(end_ptr, &end_ptr); // sum mit ausgabe von strtol beschreiben
    for (int i = 0; end_ptr != NULL;) { //solange end_ptr nicht NULL
        nb = my_strtol(end_ptr, &end_ptr); // nb mit ausgabe von  strtol füttern
        sum = sum + nb; //plusoperation ausführen
    }
    return (sum); //summe returnen
}

int eval_expr(char const *str)
{
    char *s1 = malloc(sizeof(char) * (my_strlen(str) + 1));
    int k = 0;
    int nb = 0;
    int a = 0;

    s1 = my_strcpy(s1, str);
    for (int i = 0; i < my_strlen(str); i++) {   //für die komplette länge des Strings folgendes ausführen
        if ((str[i] >= '0' && str[i] <= '9') || str[i] == 40 || str[i] == 41 ||
            str[i] == 42 || str[i] == 43 || str[i] == 45 || str[i] == 47 || 
            str[i] == 37) {  
            s1[k] = str[i];  //s1 mit charactern: 0-9, (, ), *, +, -, /, %, befüllen 
            k++; //inkremente k
        }
    }
    s1[k] = '\0';  // s1 terminieren
    nb = brackets(s1, a, k); // aufruf der Bracketsdunktion um die innerste klammer zu finden
    free(s1); // den Speicher des s1 wieder freigeben
    return (nb); //return den nb
}

int  main(int ac , char **av)
{
    if (ac == 2) {
        my_put_nbr(eval_expr(av[1])); //aufruf der eval_express mit dem 1. Argument
        my_putchar('\n');
        return (0);
    }
    return (84); //returne 84 -> für später error handling
}