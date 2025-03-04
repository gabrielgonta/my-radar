/*
** EPITECH PROJECT, 2024
** my-radar
** File description:
** Returns the percentage of an unsigned int
*/

unsigned int get_percentage(unsigned int nb, unsigned int percentage)
{
    return (nb - ((nb * (100 - percentage)) / 100));
}