/*
** EPITECH PROJECT, 2017
** pong
** File description:
** generic
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "my_csfml.h"

sfVector2f *get_speed_vector(sfVector2f *ball_t1, sfVector2f *ball_t2)
{
	sfVector2f *ball_speed = malloc(sizeof(sfVector2f));

	ball_speed->x = ball_t2->x - ball_t1->x;
	ball_speed->y = ball_t2->y - ball_t1->y;
	return (ball_speed);
}

sfVector2f *get_coordinate_time(sfVector2f *pos, sfVector2f *ball_speed, int n)
{
	sfVector2f *coordinate = malloc(sizeof(sfVector2f));

	coordinate->x = pos->x + ball_speed->x * n;
	coordinate->y = pos->y + ball_speed->y * n;
	return (coordinate);
}

float get_incidence_oppo(sfVector2f *bs)
{
	float oppo;
	float hypo;
	float val = 180.0 / PI;

	oppo = ABS(bs->y);
	hypo = sqrt(bs->x * bs->x + bs->y * bs->y);
	return (asin(oppo / hypo) * val);
}

float get_incidence_adja(sfVector2f *bs)
{
	float adja;
	float hypo;
	float val = 180.0 / PI;

	adja = ABS(bs->x);
	hypo = sqrt(bs->x * bs->x + bs->y * bs->y);
	return (asin(adja / hypo) * val);
}
