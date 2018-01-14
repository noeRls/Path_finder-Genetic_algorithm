/*
** EPITECH PROJECT, 2017
** eazy_stuff
** File description:
** fct wich made the csfml library friendly
*/

#include "my_csfml.h"
#include <stdlib.h>

sfIntRect *get_rect(int x, int y , int width, int height)
{
	sfIntRect *rect = malloc(sizeof(sfIntRect));

	rect->top = y;
	rect->left = x;
	rect->width = width;
	rect->height = height;
	return (rect);
}

sfVector2f *create_vf(float x, float y)
{
	sfVector2f *vect = malloc(sizeof(sfVector2f));

	vect->x = x;
	vect->y = y;
	return (vect);
}
