/*
** EPITECH PROJECT, 2023
** my-radar
** File description:
** Header file for events
*/

#ifndef EVENTS_H_
    #define EVENTS_H_

    #include <SFML/Graphics.h>
    #include "sim.h"

    void start_menu_poll_events(sfRenderWindow *render, int *exit_code);

    void sim_poll_events(window_t *window, states_t *state);
    void check_window_quit(sfEvent *event, sfRenderWindow *window);
    void switch_pressed_key(sfEvent *event, window_t *window, states_t *states);

    void pause_sim(window_t *window, states_t *state);
#endif