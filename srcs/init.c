/*
** EPITECH PROJECT, 2018                                                        
** lemipc.h                                                                     
** File description:                                                            
** lemipc                                                                       
*/

#include "lemipc.h"

int init_ftok(char **av)
{
	key_t key;

	if ((key = ftok(av[1], 0)) == -1) {
		fprintf(stderr, "%s: bad path\n", av[1]);
		exit(84);
	}
	return (key);
}

void init_first_game(t_ipcs *ipcs, int team)
{
	void *addr;
	int pos;

	if ((addr = shmat(ipcs->shm_id, NULL, SHM_R | SHM_W)) != NULLE) {
		addr = creat_map(ipcs->key, addr, &ipcs->sem_id);
		pos = creat_champion((t_tab *)addr, team, ipcs->sem_id);
		if (fork() == 0)
			aff_map(addr, ipcs);
		else
			player_loop((t_tab *)addr, pos, ipcs);
	}
}

void init_ipcs(t_ipcs *ipcs, char **av)
{
	ipcs->sem_id = 0;
	ipcs->shm_id = 0;
	ipcs->msg_id = 0;
	ipcs->key = init_ftok(av);
}

void fist_run(t_ipcs *ipcs, char *team)
{
	if ((ipcs->shm_id =
	shmget(ipcs->key, (sizeof(t_tab) * SIZE), CREATE)) != -1)
		init_first_game(ipcs, atoi(team));
}

void other_run(t_ipcs *ipcs, char *team)
{
	int pos;
	void *add;

	ipcs->sem_id = semget(ipcs->key, 1, GET);
	ipcs->msg_id = msgget(ipcs->key, GET);
	if ((add = shmat(ipcs->shm_id, NULL, GET)) != NULLE)
		pos = creat_champion((t_tab *)add, atoi(team), ipcs->sem_id);
	player_loop((t_tab *)add, pos, ipcs);
}
