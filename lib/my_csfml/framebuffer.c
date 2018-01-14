/*
** EPITECH PROJECT, 2017
** framebuffer
** File description:
** fct
*/

#include "my_csfml.h"
#include <stdlib.h>

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
	framebuffer_t *fb = malloc(sizeof(framebuffer_t));

	fb->width = width;
	fb->height = height;
	fb->pixels = malloc(sizeof(sfUint8) * width * height * 4);
	return (fb);
}
void my_put_pixel(framebuffer_t *buffer, unsigned int x, \
		unsigned int y, sfColor color)
{
	int pos;

	pos = (buffer->width * y + x) * 4;
	buffer->pixels[pos]  = color.r;
	buffer->pixels[pos + 1] = color.g;
	buffer->pixels[pos + 2] = color.b;
	buffer->pixels[pos + 3] = color.a;
}
