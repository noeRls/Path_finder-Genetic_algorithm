/*
** EPITECH PROJECT, 2017
** calcs
** File description:
** calcs for inds
*/

#include <math.h>
#include "graphic.h"
#include "genetic.h"

int *get_indexes(int size)
{
	int *tab = malloc(sizeof (int) * size);

	for (int i = 0; i < size; i++) {
		tab[i] = i;
	}
	return (tab);
}

float get_length(sfVector2f const *a, sfVector2f const *b)
{
	int length = 0;

	length = sqrt((a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y));
	return (length);
}

void set_fitness(species_t **tab, int nb_sp, sfVector2f const *end)
{
	int *max;
	int tmp;

	for (int i = 0; i < nb_sp; i++) {
		max = get_indexes(tab[i]->p_size);
		for (int j = 0; j < tab[i]->p_size - 1; j++) {
			if (get_length(tab[i]->popu[max[j]]->pos, end) > get_length(tab[i]->popu[max[j + 1]]->pos, end)) {
				tmp = max[j];
				max[j] = max[j + 1];
				max[j + 1] = tmp;
				j = -1;
			}
		}
		tab[i]->fitness_rank = max;
	}
}
