/*
** EPITECH PROJECT, 2017
** update_map
** File description:
** update the map, when user is drawing it
*/

#include "graphic.h"

void draw_sq(framebuffer_t *buffer, sfVector2f *pos, float size, sfColor color)
{
	sfVector2f *eazy_pos = create_vf(pos->x - (size / 2), \
					pos->y - (size / 2));

	for (float y = eazy_pos->y; y < size + eazy_pos->y; y++) {
		for (float x = eazy_pos->x; x < size + eazy_pos->x; x++) {
			if (IS_IN_WINDOW(x, y)) {
				my_put_pixel(buffer, x, y, color);
			}
		}
	}
}

void update_map(graph_t *graph)
{
	if (graph->clicked) {
		draw_sq(graph->fbuff, graph->mouse_pos, DRAWING_SQ_SIZE, DRAW_COLOR);
	}
}
