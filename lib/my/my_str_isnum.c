/*
** EPITECH PROJECT, 2017
** my_str_isnum
** File description:
** returns 1 if the string passed as parameter only contains digits
*/

#include "my.h"

int my_str_isnum(char const *str)
{
	int i = 0;
	int lenght = 0;

	lenght = my_strlen(str);
	if (lenght == 0)
		return (1);
	while (str[i] != '\0') {
		if (!(str[i] > 47 && str[i] < 58))
			return (0);
		i ++;
	}
	return (1);
}
