/*
** EPITECH PROJECT, 2023
** my-radar
** File description:
** Header file for window structure
*/

#ifndef WINDOW_H_
    #define WINDOW_H_

    #include <SFML/Graphics.h>

    #define W_WIDTH         1920
    #define W_HEIGHT        1080
    #define W_BPP           32
    #define W_MAX_FPS       30
    #define W_TITLE         "my-radar"

    typedef struct window {
        sfRenderWindow *render;
        unsigned int width;
        unsigned int height;
        sfSprite *background;
    } window_t;

    window_t *window_create(unsigned int width, unsigned int height,
                            char const *window_title);
    void window_destroy(window_t *window);
    void window_set_background(window_t *window, sfTexture *texture);
#endif