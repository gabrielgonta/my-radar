/*
** EPITECH PROJECT, 2023
** my-radar
** File description:
** Returns the number of characters in a string
*/

unsigned int my_strlen(char const *str)
{
    unsigned int len = 0;

    while (str[len])
        len++;
    return (len);
}