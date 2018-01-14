/*
** EPITECH PROJECT, 2017
** graphic_creation
** File description:
** used to initialise the graphic
*/

#include "graphic.h"

graph_t *graph_creation(void)
{
	graph_t *graph = malloc(sizeof(graph_t));
	sfVideoMode mode = {WW, WH, 8};

	graph->window = sfRenderWindow_create(mode, "path finder", \
					sfDefaultStyle, NULL);
	graph->started = 0;
	graph->clicked = 0;
	graph->mouse_pos = create_vf(0, 0);
	graph->start_pos = create_vf(WW / 4, WH / 2);
	graph->arrival_pos = create_vf(3 * (WW / 4), WH / 2);

	graph->fbuff = framebuffer_create(WW, WH);
	graph->fbuff_txt = sfTexture_create(WW, WH);
	graph->fbuff_sprite = sfSprite_create();
	sfSprite_setTexture(graph->fbuff_sprite, graph->fbuff_txt, 0);
	reset_framebuffer(graph->fbuff);

	graph->sbuff = framebuffer_create(WW, WH);
	graph->sbuff_txt = sfTexture_create(WW, WH);
	graph->sbuff_sprite = sfSprite_create();
	sfSprite_setTexture(graph->sbuff_sprite, graph->sbuff_txt, 0);
	reset_framebuffer(graph->sbuff);

        graph->start = sfCircleShape_create();
	graph->arrival = sfCircleShape_create();
	sfCircleShape_setRadius(graph->start, 15);
	sfCircleShape_setRadius(graph->arrival, 15);
	sfCircleShape_setFillColor(graph->start, sfGreen);
	sfCircleShape_setFillColor(graph->arrival, sfYellow);
	return (graph);
}
