/*
** EPITECH PROJECT, 2017
** my_csfml
** File description:
** header
*/

#ifndef MY_CSFML
#define MY_CSFML

#include <SFML/Graphics.h>

#define PI 3.14159265
#define ABS(value) (((value) < 0 ? ((value) * -1) : (value)))

#define CLOCK_TIME(clock) sfClock_getElapsedTime((clock)).microseconds

typedef struct framebuffer {
	unsigned int width;
	unsigned int height;
	sfUint8 *pixels;
} framebuffer_t;

sfRenderWindow *create_window(int x, int y, int z, char *name);
framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
void my_put_pixel(framebuffer_t *buffer, unsigned int x, unsigned int y, sfColor color);
sfIntRect *get_rect(int x, int y , int width, int height);
sfVector2f *create_vf(float x, float y);
sfVector2f *get_speed_vector(sfVector2f *ball_t1, sfVector2f *ball_t2);
sfVector2f *get_coordinate_time(sfVector2f *pos, sfVector2f *ball_speed, int n);
float get_incidence_oppo(sfVector2f *bs);
float get_incidence_adja(sfVector2f *bs);

#endif
