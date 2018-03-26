/*
** EPITECH PROJECT, 2018                                                        
** lemipc.h                                                                     
** File description:                                                            
** lemipc                                                                       
*/

#include "lemipc.h"

int check_place(t_tab *tab)
{
	int i = 0;

	while (i < SIZE) {
		if (tab[i].team == 0)
			return (0);
		i++;
	}
	return (1);
}

int creat_champion(t_tab *tab, int team, int sem_id)
{
	int pos;

	lock(sem_id);
	if (check_place(tab) == 1) {
		unlock(sem_id);
		exit(0);
	}
	pos = (rand() % (SIZE - 1));
	while (tab[pos].team != 0)
		pos = (rand() % (SIZE - 1));
	tab[pos].team = team;
	unlock(sem_id);
	return (pos);
}
