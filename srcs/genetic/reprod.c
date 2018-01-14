/*
** EPITECH PROJECT, 2017
** reprod
** File description:
** reprod
*/

#include "genetic.h"

int mut(float mut_rate)
{
	mut_rate = 1 / mut_rate;
	if (rand() % (int) mut_rate == 0) {
		return (rand() % 2 == 0 ? 1 : -1);
	}
	return (0);
}

individual_t *mix_dna(individual_t *fat, individual_t *mot, float mut_rate)
{
	individual_t **parents = malloc(sizeof (individual_t *) * 2);
	individual_t *child = create_individual(DNA_SIZE);

	parents[0] = fat;
	parents[1] = mot;
	for (int i = 0; i < DNA_SIZE; i++) {
		child->dna[i] = parents[rand() % 2]->dna[i];
		child->dna[i] = (child->dna[i] + mut(mut_rate)) % NBR_DIRECTION;
	}
	free(parents);
	return (child);
}

void reprod(species_t **tab, int size)
{
	individual_t **inds;
	individual_t *father;
	individual_t *mother;
	int mother_ind = 0;
	int father_ind = 0;

	for (int i = 0; i < size; i++) {
		inds = malloc(sizeof (individual_t *) * POPU_SIZE);
		for (int j = 0; j < tab[i]->p_size; j++) {
			father_ind = rand() % 4;
			mother_ind = rand() % 4;
			while (mother_ind == father_ind)
				mother_ind = rand() % 4;

			father = tab[i]->popu[tab[i]->fitness_rank[father_ind]];
			mother = tab[i]->popu[tab[i]->fitness_rank[rand() % 4]];
			inds[j] = mix_dna(father, mother, tab[i]->mutation_rate);
		}
		tab[i]->popu = inds;
		tab[i]->nbr_alive = POPU_SIZE;
	}
}

void start_reprod(species_t **tab, int size, sfVector2f const *end)
{
	set_fitness(tab, size, end);
	reprod(tab, size);
	printf("size of pop : %d\n", tab[0]->p_size);
}
