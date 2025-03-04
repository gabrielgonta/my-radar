/*
** EPITECH PROJECT, 2023
** my-radar
** File description:
** pause_sim
*/

#include <SFML/Graphics.h>
#include "sim.h"
#include "draw.h"

void pause_sim(window_t *window, states_t *state)
{
    if (state->is_paused) {
        state->is_paused = sfFalse;
    } else {
        draw_pause_menu(window);
        state->is_paused = sfTrue;
    }
}