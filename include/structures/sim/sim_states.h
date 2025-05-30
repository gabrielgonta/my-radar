/*
** EPITECH PROJECT, 2023
** my-radar
** File description:
** Header file for structure sim_states
*/

#ifndef STATES_H_
    #define STATES_H_

    #include <SFML/Graphics.h>

    typedef sfBool Bool;

    typedef struct sim_states {
        Bool show_hitbox;
        Bool show_sprites;
        Bool show_quadtree;
        Bool show_info;
        Bool is_paused;
    } sim_states_t;
    typedef sim_states_t states_t;

    sim_states_t *sim_states_create(void);
    void sim_states_destroy(sim_states_t *);
#endif