/*
** EPITECH PROJECT, 2017
** window_tool
** File description:
** fct for window manipulation
*/

#include "my_csfml.h"

sfRenderWindow *create_window(int x, int y, int z, char *name)
{
	sfVideoMode mode = {x, y, z};

	return (sfRenderWindow_create(mode, name, sfDefaultStyle, NULL));
}
