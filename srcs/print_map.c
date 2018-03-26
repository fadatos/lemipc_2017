/*
** EPITECH PROJECT, 2018                                                        
** lemipc.h                                                                     
** File description:                                                            
** lemipc                                                                       
*/

#include "lemipc.h"

int  alone(t_tab *map)
{
	int   x = 0;
	int   save_team;

	save_team = map[0].team;
	while (x < SIZE) {
		if (map[x].team != 0 && save_team == 0)
			save_team = map[x].team;
		else if (map[x].team != 0 && save_team != map[x].team &&
		save_team != 0)
			return (0);
		x++;
	}
	return (1);
}

void print_ligne1(void)
{
	int   i = 0;

	printf("+");
	while (i < W) {
		printf("-");
		i++;
	}
	printf("+\n");
}

void print_other(t_tab *map)
{
	int   i = 0;

	printf("|");
	while (i < SIZE) {
		if (map[i].team > 0)
			printf("%d", map[i].team);
		else
			printf(" ");
		i++;
		if (i % W == 0)
			printf("|\n|");
	}
}

void display_map(t_tab *map)
{
	system("clear");
	print_ligne1();
	print_other(map);
	print_ligne1();
	printf("nombre de champion restant = %i\n", count_alive(map));
}

void    aff_map(t_tab *map, t_ipcs *ipcs)
{
	int   i = 0;

	while (alone(map) == 1)
		usleep(1);
	while (alone(map) != 1) {
		lock(ipcs->sem_id);
		display_map(map);
		usleep(100000);
		unlock(ipcs->sem_id);
	}
	usleep(100000);
	unlock(ipcs->sem_id);
	display_map(map);
	while (i < SIZE && map[i].team == 0)
		i++;
	printf("TEAM %i WON THEY ARE GOOD GUYS YEAH !\n", map[i].team);
	destroy_ipcs(ipcs);
}
