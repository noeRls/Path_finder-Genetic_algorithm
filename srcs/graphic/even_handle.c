/*
** EPITECH PROJECT, 2017
** even_handle
** File description:
** handle user input
*/

#include "graphic.h"

static void manage_map_drawing_event(graph_t *graph, sfEvent event)
{
	if (event.type == sfEvtMouseMoved) {
		graph->mouse_pos->x = event.mouseMove.x;
		graph->mouse_pos->y = event.mouseMove.y;
	}
	if (event.type == sfEvtMouseButtonPressed)
		graph->clicked = graph->clicked ? 0 : 1;
	if (sfKeyboard_isKeyPressed(sfKeyA)) {
		graph->start_pos->x = graph->mouse_pos->x;
		graph->start_pos->y = graph->mouse_pos->y;
	}
	if (sfKeyboard_isKeyPressed(sfKeyZ)) {
		graph->arrival_pos->x = graph->mouse_pos->x;
		graph->arrival_pos->y = graph->mouse_pos->y;
	}
	if (sfKeyboard_isKeyPressed(sfKeySpace))
		graph->started = 1;
}

void even_handle(graph_t *graph)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(graph->window, &event)) {
		if (event.type == sfEvtClosed || \
		sfKeyboard_isKeyPressed(sfKeyEscape))
			sfRenderWindow_close(graph->window);
		if (!START) {
			manage_map_drawing_event(graph, event);
		}
	}
}
