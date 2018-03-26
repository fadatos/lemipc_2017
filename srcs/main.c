/*
** EPITECH PROJECT, 2018                                                        
** lemipc.h                                                                     
** File description:                                                            
** lemipc                                                                       
*/

#include "lemipc.h"

t_tab	*creat_map(key_t key, t_tab *map, int *sem_id)
{
	int pos = 0;

	if ((*sem_id = semget(key, 1, IPC_CREAT | SHM_R | SHM_W)) == -1)
		return (NULL);
	semctl(*sem_id, 0, SETVAL, 1);
	while (pos < SIZE) {
		map[pos].team = 0;
		pos++;
	}
	return (map);
}

void player_loop(t_tab *add, int pos, t_ipcs *ipcs)
{
	int life = 1;

	while (life) {
		lock(ipcs->sem_id);
		pos = move_champ(add, pos);
		life = last(add, pos);
		unlock(ipcs->sem_id);
		usleep(100000);
	}
}

int init_lemipc(char **av)
{
	t_ipcs *ipcs;

	if ((ipcs = malloc(sizeof(t_ipcs))) == NULL)
		return (84);
	init_ipcs(ipcs, av);
	if ((ipcs->shm_id =
	shmget(ipcs->key, (sizeof(t_tab) * SIZE), GET)) == -1)
		fist_run(ipcs, av[2]);
	else
		other_run(ipcs, av[2]);
	return (0);
}

int main(int ac, char **av)
{
	if (ac != 3 || check_nb(av[2]) == 1) {
		fprintf(stderr, "Usage: %s PATH NB_TEAM \n", av[0]);
		return (84);
	}
	return (init_lemipc(av));
}
