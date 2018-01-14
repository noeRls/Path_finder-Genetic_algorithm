/*
** EPITECH PROJECT, 2017
** run
** File description:
** fct call to run graph interface
*/

#include "graphic.h"

int all_dead(species_t **species)
{
	for (int i = 0; i < NBR_SPECIES; i++)
		if (species[i]->nbr_alive > 0) {
			return (0);
		}
	return (1);
}

void run(graph_t *graph, species_t **species)
{
	sfClock *clock = sfClock_create();
	unsigned int frame = 0;

	while(sfRenderWindow_isOpen(graph->window)) {
		if (!START)
			update_map(graph);
		if ((CLOCK_TIME(clock) > 0 && START)) {
			update_species(graph, species, frame);
			frame++;
			sfClock_restart(clock);
		}
		render(graph, species);
		if (all_dead(species)) {
			start_reprod(species, NBR_SPECIES, graph->arrival_pos);
			frame = 0;
		}
		even_handle(graph);
	}
}
