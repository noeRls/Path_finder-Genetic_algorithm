/*
** EPITECH PROJECT, 2017
** initialisation
** File description:
** initilise_all_species
*/

#include "graphic.h"
#include "genetic.h"

individual_t *create_individual(int size)
{
	individual_t *individual = malloc(sizeof(individual_t));

	individual->dna = malloc(sizeof(char) * size);
	for (int i = 0; i < size; i++) {
		individual->dna[i] = rand() % NBR_DIRECTION;
	}
	individual->alive = 1;
	return (individual);
}

species_t *ini_spe(float mr, char const *name)
{
	species_t *species = malloc(sizeof(species_t));

	species->name = strdup(name);
	species->mutation_rate = mr;
	species->popu = malloc(sizeof(individual_t *) * POPU_SIZE);
	species->p_size = POPU_SIZE;
	for (int i = 0; i < POPU_SIZE; i++) {
		species->popu[i] = create_individual(DNA_SIZE);
		species->color = &sfRed;
	}
	species->nbr_alive = POPU_SIZE;
	return (species);
}
