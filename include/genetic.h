/*
** EPITECH PROJECT, 2017
** genetic
** File description:
** header
*/

#ifndef GENETIC
#define GENETIC

#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics.h>

#define NBR_SPECIES 1
#define POPU_SIZE 50
#define DNA_SIZE 5000

#define	NBR_DIRECTION 3

#define	STRAIGHT 0
#define	LEFT 1
#define RIGHT 2

typedef struct individual {
	char *dna; //array of direction 0->sraight ahead 1->left 2->right
	sfVector2f *pos;
	sfVector2f *move;
	int alive;
} individual_t;

typedef struct species {
	char *name;
	sfColor *color;
	float mutation_rate;
	int *fitness_rank;
	individual_t **popu; //all the population
	int nbr_alive;
	int p_size;
} species_t;

void start_reprod(species_t **tab, int size, sfVector2f const *end);
individual_t *create_individual(int size);
species_t *ini_spe(float mr, char const *name);
void set_fitness(species_t **tab, int nb_sp, sfVector2f const *end);

#endif
