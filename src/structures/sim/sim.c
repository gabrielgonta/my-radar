/*
** EPITECH PROJECT, 2023
** my-radar
** File description:
** Source file for simulation structure
*/

#include <stdlib.h>
#include <SFML/System.h>
#include "sim.h"
#include "file_manipulation.h"
#include "window.h"
#include "plane.h"
#include "tower.h"
#include "my.h"

sim_t *sim_create(window_t *window)
{
    sim_t *sim = malloc(sizeof(sim_t));

    if (!sim)
        return (NULL);
    sim->gl = gl_create(window);
    sim->state = sim_states_create();
    sim->info = sim_info_create();
    sim->clock = sfClock_create();
    sim->quadtree = quadtree_create((sfIntRect) {0, 0, sim->gl->window->width,
                                                sim->gl->window->height});
    sim->planes = NULL;
    sim->towers = NULL;
    if (!(sim->gl) || !(sim->quadtree) || !(sim->clock))
        return (NULL);
    return (sim);
}

sim_t *sim_create_from_script(window_t *window, char const *script_path)
{
    sim_t *sim = sim_create(window);

    if (!sim)
        return (NULL);
    if (get_entities_from_file(script_path, sim) != 0)
        return (NULL);
    sfText_setString(sim->gl->texts->nb_planes, my_strdupcat(
        "Total planes : ", my_int_to_strnum(sim->info->nb_planes)));
    sfText_setString(sim->gl->texts->nb_towers, my_strdupcat(
        "Total towers : ", my_int_to_strnum(sim->info->nb_towers)));
    return (sim);
}

void sim_destroy(sim_t *sim)
{
    gl_destroy(sim->gl);
    sfClock_destroy(sim->clock);
    sim_info_destroy(sim->info);
    sim_states_destroy(sim->state);
    for (unsigned int i = 0 ; sim->towers[i] ; i++)
        tower_destroy(sim->towers[i]);
    for (unsigned int i = 0 ; sim->planes[i] ; i++)
        plane_destroy(sim->planes[i]);
    if (sim->quadtree) {
        quadtree_clear(sim->quadtree);
        free(sim->quadtree);
    }
    if (sim)
        free(sim);
}