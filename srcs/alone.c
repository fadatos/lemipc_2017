/*
** EPITECH PROJECT, 2018
** lemipc.h
** File description:
** lemipc
*/

#include "lemipc.h"

static int exist_another(int *check, int pos)
{
	int i = 0;

	while (i < 8) {
		if (i != pos && check[i] == check[pos])
			return (1);
		i++;
	}
	return (0);
}

static int check_double(int *check, int current_team)
{
	int i = 0;

	while (i < 8) {
		if (check[i] != current_team
		&& exist_another(check, i) == 1 && check[i] != 0)
			return (0);
		i++;
	}
	return (1);
}

int last(t_tab *tab, int pos)
{
	int check[8];
	int i;

	check[0] = ((i = pos + 1) > SIZE) ? 0 : tab[i].team;
	check[1] = ((i = pos + W + 1) > SIZE) ? 0 : tab[i].team;
	check[2] = ((i = pos + W) > SIZE) ? 0 : tab[i].team;
	check[3] = ((i = pos + W - 1) > SIZE) ? 0 : tab[i].team;
	check[4] = ((i = pos - 1) < 0) ? 0 : tab[i].team;
	check[5] = ((i = pos - W - 1) < 0) ? 0 : tab[i].team;
	check[6] = ((i = pos - W) < 0) ? 0 : tab[i].team;
	check[7] = ((i = pos - W + 1) < 0) ? 0 : tab[i].team;
	if (check_double(check, tab[pos].team) == 0) {
		tab[pos].team = 0;
		return (0);
	}
	return (1);
}
