/*
** EPITECH PROJECT, 2023
** my-radar
** File description:
** Header file for my-radar core functions
*/

#ifndef my-radar_H_
    #define my-radar_H_

    #include <SFML/Graphics.h>
    #include "sim.h"
    #include "window.h"

    int my-radar(window_t *window, char const *script_path);
    int start_menu(window_t *window);

    int launch_simulation(window_t *window, char const *script_path);
    void simulation_loop(sim_t *sim);
    void plane_loop(plane_t *plane, sim_t *sim, unsigned int c_time);
    void insert_planes_in_quadtree(plane_t **planes, quadtree_t *quadtree,
                                unsigned int c_time);
    void update_info_text(texts_t *texts, info_t *info);
#endif