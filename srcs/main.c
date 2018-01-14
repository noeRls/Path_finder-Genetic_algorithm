/*
** EPITECH PROJECT, 2017
** main
** File description:
** of the project
*/

#include "graphic.h"
#include "genetic.h"
#include <time.h>
#include <errno.h>

const char *names[] = {"alpha", "beta", "charlie"};
const float mrs[] = {0.01, 0.01, 0.01};

void print_help(void)
{
	FILE *fd = fopen("README.md", "r");
	size_t tmp = 0;

	if (fd) {
		for (char *str = NULL; getline(&str, &tmp, fd) != - 1; tmp = 0) {
			printf("%s", str);
		}
		putchar('\n');
	} else {
		perror("open readme");
	}
}

int manage_arg(int ac, char **av)
{
	if (ac < 2)
		return (1);
	if (strcmp(av[1], "-h") == 0 || strcmp(av[1], "--help") == 0) {
		print_help();
		return (0);
	}
	return (1);
}

species_t **ini_species(void)
{
	species_t **species = malloc(sizeof(species_t *) * NBR_SPECIES);

	for (int i = 0; i < NBR_SPECIES; i++) {
		species[i] = ini_spe(mrs[i], names[i]);
	}
	return (species);
}

int main(int ac, char **av)
{
	graph_t *graph;
	species_t **species = ini_species();

	if (manage_arg(ac, av)) {
		srand(time(NULL));
		graph = graph_creation();
		run(graph, species);
	}
	return (0);
}
