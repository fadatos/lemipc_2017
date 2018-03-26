/*                                    
** EPITECH PROJECT, 2018                                                        
** lemipc.h                                                                     
** File description:                                                            
** lemipc                                                                       
*/

#include "lemipc.h"

int check_nb(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

void destroy_ipcs(t_ipcs *ipcs)
{
	semctl(ipcs->sem_id, 1, IPC_RMID);
	shmctl(ipcs->shm_id, IPC_RMID, NULL);
	msgctl(ipcs->msg_id, IPC_RMID, NULL);
	exit(0);
}

int lock(int sem_id)
{
	struct sembuf occup;

	occup.sem_num = 0;
	occup.sem_flg = 0;
	occup.sem_op = -1;
	if (semop(sem_id, &occup, 1) == -1) {
		unlock(sem_id);
		exit(0);
	}
	return (0);
}

void unlock(int sem_id)
{
	struct sembuf occup;

	occup.sem_num = 0;
	occup.sem_flg = 0;
	occup.sem_op = 1;
	semop(sem_id, &occup, 1);
}

int  count_alive(t_tab *map)
{
	int   nb = 0;
	int   x = 0;

	while (x < SIZE) {
		if (map[x].team != 0)
			nb++;
		x++;
	}
	return (nb);
}
