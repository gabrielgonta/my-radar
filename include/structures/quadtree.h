/*
** EPITECH PROJECT, 2023
** my-radar
** File description:
** Header file for quadtree structure
*/

#ifndef QUADTREE_H_
    #define QUADTREE_H_

    #include <SFML/Graphics.h>
    #include "plane.h"

    #define QT_CAPACITY      4

    typedef struct quadtree {
        sfIntRect boundary;
        plane_t **planes;
        unsigned int nb_planes;
        struct quadtree **children;
        sfBool is_divided;
    } quadtree_t;

    quadtree_t *quadtree_create(sfIntRect boundary);
    void quadtree_clear(quadtree_t *quadtree);
    int quadtree_insert(quadtree_t *quadtree, plane_t *plane);
    plane_t **quadtree_query(quadtree_t *quadtree, sfIntRect const area);
    unsigned int quadtree_get_nb_planes_in_area(quadtree_t *quadtree,
                                            sfIntRect const area);
    int quadtree_subdivide(quadtree_t **quadtree);
#endif