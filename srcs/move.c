/*
** EPITECH PROJECT, 2018                                                        
** lemipc.h                                                                     
** File description:                                                            
** lemipc                                                                       
*/

#include "lemipc.h"

int		move_champ(t_tab *tab, int from)
{
	int		team_save;
	int		to;

	team_save = tab[from].team;

	to = (rand() % (SIZE - 1));
	while (tab[to].team != 0)
		to = (rand() % (SIZE - 1));
	tab[from].team = 0;
	tab[to].team = team_save;
	return (to);
}
