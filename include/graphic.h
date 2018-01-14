/*
** EPITECH PROJECT, 2017
** graphic
** File description:
** header
*/

#ifndef GRAPHIC
#define GRAPHIC

#include "my_csfml.h"
#include <stdio.h>
#include <stdlib.h>
#include "genetic.h"
#include <string.h>

//green color is not colliding

#define WH 800
#define WW 1280

#define DRAWING_SQ_SIZE 15
#define DRAW_COLOR sfWhite
#define SPECIES_DRAW_SIZE 5

#define SPEED 10

#define START graph->started
#define IS_IN_WINDOW(x, y) (x >= 0 || y >= 0 || x <= WW || y <= WH)

#define OFFSET_COLLIDE DRAWING_SQ_SIZE + 1

typedef struct graph_t {
	sfRenderWindow *window;
	int started;
	int clicked;
	sfVector2f *mouse_pos;
	sfVector2f *start_pos;
	sfVector2f *arrival_pos;
	sfCircleShape *arrival;
	sfCircleShape *start;
	framebuffer_t *fbuff;
	sfTexture *fbuff_txt;
	sfSprite *fbuff_sprite;
	sfTexture *sbuff_txt;
	sfSprite *sbuff_sprite;
	framebuffer_t *sbuff;
} graph_t;

void even_handle(graph_t *graph);
graph_t *graph_creation(void);
void run(graph_t *graph, species_t **species);
void render(graph_t *graph, species_t **species);

void update_species(graph_t *graph, species_t **species, unsigned int frame);

void update_map(graph_t *graph);
void draw_sq(framebuffer_t *buffer, sfVector2f *pos, float size, sfColor color);

void reset_framebuffer(framebuffer_t *buff);

#endif
