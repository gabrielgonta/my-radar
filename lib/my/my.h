/*
** EPITECH PROJECT, 2023
** my-radar
** File description:
** Header file for libmy
*/

#ifndef MY_H_
    #define MY_H_

    void my_putchar(char c);
    void my_putstr(char const *str);
    void my_puterr(char const *str);

    int my_strcmp(char const *s1, char const *s2);
    int my_strtol(char *str, char **endptr);
    unsigned int my_count_char(char const *str, char const to_count);
    unsigned int my_intlen(int nb);
    unsigned int my_strlen(char const *str);

    char *my_int_to_strnum(int nb);
    char *my_revstr(char *str);
    char *my_strcat(char *dest, char const *src);
    char *my_strdupcat(char const *s1, char const *s2);
#endif