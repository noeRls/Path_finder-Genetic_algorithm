/*
** EPITECH PROJECT, 2017
** update_graph
** File description:
** update th graphics data
*/

#include "graphic.h"

void ini_indi(individual_t *indi, graph_t *graph)
{
	indi->pos = create_vf(graph->start_pos->x, graph->start_pos->y);
	indi->move = create_vf(1, 0);
}

void update_indi(individual_t *indi, unsigned int frame)
{
	float tmp = indi->move->x;

	if (indi->alive) {
		if (indi->dna[frame] == LEFT) {
			if (indi->move->x && !indi->move->y) {
				indi->move->y = indi->move->x;
			} else if (indi->move->y && !indi->move->x) {
				indi->move->x = indi->move->y * -1;
			} else if (indi->move->x && indi->move->y) {
				indi->move->x = indi->move->x - indi->move->y == 0 ? 0 : indi->move->x;
				indi->move->y = indi->move->x + indi->move->y == 0 ? 0 : indi->move->y;
			}
		}
		if (indi->dna[frame] == RIGHT) {
			if (indi->move->x && !indi->move->y) {
				indi->move->y = indi->move->x * -1;
			} else if (indi->move->y && !indi->move->x) {
				indi->move->x = indi->move->y;
			} else if (indi->move->x && indi->move->y) {
				indi->move->x = indi->move->x + indi->move->y == 0 ? 0 : indi->move->x;
				indi->move->y = indi->move->x - indi->move->y == 0 ? 0 : indi->move->y;
			}
		}
		indi->pos->x += indi->move->x * SPEED;
		indi->pos->y += indi->move->y * SPEED;
	}
}

void update_species(graph_t *graph, species_t **species, unsigned int frame)
{
	for (int spec = 0; spec < NBR_SPECIES; spec++) {
		for (int indi = 0; indi < POPU_SIZE; indi++) {
			if (frame == 0)
				ini_indi(species[spec]->popu[indi], graph);
			else
				update_indi(species[spec]->popu[indi], frame);
		}
	}
}
