/*
** EPITECH PROJECT, 2017
** render
** File description:
** graph_render
*/

#include "graphic.h"

void reset_framebuffer(framebuffer_t *buff)
{
	int pos = 0;

	for (int x = 0; x < buff->width; x++) {
		for (int y = 0; y < buff->height; y++) {
			pos = (buff->width * y + x) * 4;
			buff->pixels[pos] = 0;
			buff->pixels[pos + 1] = 0;
			buff->pixels[pos + 2] = 0;
			buff->pixels[pos + 3] = 0;
		}
	}
}

int is_pixel_on(sfVector2f *pos, sfImage *image)
{
	sfColor color = sfImage_getPixel(image, pos->x, pos->y);

	if (color.r == 0 && color.b == 0)
		return (0);
	return (1);
}

void manage_indi_collide(individual_t *indi, sfImage *image, species_t *specie)
{
	int tmp = WH;

	tmp -= OFFSET_COLLIDE;
	if (indi->alive) {
		if (is_pixel_on(indi->pos, image) \
		    || indi->pos-> x >= WW - OFFSET_COLLIDE || \
		    indi->pos->x <= OFFSET_COLLIDE ||	       \
		    indi->pos->y <= OFFSET_COLLIDE || \
		    indi->pos->y >= tmp) {
			indi->alive = 0;
			specie->nbr_alive -= 1;
		}
	}
}

void check_collide(graph_t *graph, species_t **species)
{
	sfImage *image = sfRenderWindow_capture(graph->window);

	for (int spec = 0; spec < NBR_SPECIES; spec++) {
		for (int indi = 0; indi < POPU_SIZE; indi++) {
			manage_indi_collide(species[spec]->popu[indi], image, species[spec]);
		}
	}
	sfImage_destroy(image);
}

void render_indi(species_t **species, graph_t *graph)
{
	for (int spec = 0; spec < NBR_SPECIES; spec++) {
		for (int indi = 0; indi < POPU_SIZE; indi++) {
			draw_sq(graph->sbuff, species[spec]->popu[indi]->pos, SPECIES_DRAW_SIZE, \
				*(species[spec]->color));
		}
	}
	sfTexture_updateFromPixels(graph->sbuff_txt, graph->sbuff->pixels, \
				   WW, WH, 0, 0);
	sfRenderWindow_drawSprite(graph->window, graph->sbuff_sprite, NULL);
}

void render_arrival_start(graph_t *graph)
{
	if (!START) {
		sfCircleShape_setPosition(graph->start, *(graph->start_pos));
		sfCircleShape_setPosition(graph->arrival, *(graph->arrival_pos));
	}
	sfRenderWindow_drawCircleShape(graph->window, graph->start, 0);
	sfRenderWindow_drawCircleShape(graph->window, graph->arrival, 0);
}

void render(graph_t *graph, species_t **species)
{
	sfRenderWindow_clear(graph->window, sfBlack);
	sfRenderWindow_drawSprite(graph->window, graph->fbuff_sprite, NULL);
	render_arrival_start(graph);
	if (!START) {
		sfTexture_updateFromPixels(graph->fbuff_txt, graph->fbuff->pixels, \
					   WW, WH, 0, 0);
	} else {
		reset_framebuffer(graph->sbuff);
		check_collide(graph, species);
		render_indi(species, graph);
	}
	sfRenderWindow_display(graph->window);
}
