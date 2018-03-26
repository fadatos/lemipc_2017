/*
** EPITECH PROJECT, 2018                                                        
** lemipc.h                                                                     
** File description:                                                            
** lemipc                                                                       
*/

#ifndef LEMIPC_H__
# define LEMIPC_H__

# include <sys/types.h>
# include <sys/ipc.h>
# include <sys/sem.h>
# include <sys/msg.h>
# include <sys/shm.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# define L 50
# define W 50
# define SIZE L * W
# define CREATE IPC_CREAT | SHM_R | SHM_W
# define GET SHM_R | SHM_W
# define NULLE (void *) -1

typedef struct  t_tab
{
	int team;
}t_tab;

typedef struct	s_ipcs
{
	key_t	key;
	int	sem_id;
	int	shm_id;
	int	msg_id;
}t_ipcs;

/* alone.c */
int last(t_tab *tab, int pos);
/* drop_team.c */
int	creat_champion(t_tab *tab, int team, int sem_id);
/* init.c */
int init_ftok(char **av);
void init_ipcs(t_ipcs *ipcs, char **av);
void fist_run(t_ipcs *ipcs, char *team);
void other_run(t_ipcs *ipcs, char *team);
void init_first_game(t_ipcs *ipcs, int team);
/* main.c */
void player_loop(t_tab *add, int pos, t_ipcs *ipcs);
t_tab *creat_map(key_t, t_tab *add, int *sem_id);
/* move.c */
int move_champ(t_tab *add, int pos);
/* print_map.c */
void aff_map(t_tab *map, t_ipcs *ipcs);
void display_map(t_tab *map);
void print_other(t_tab *map);
void print_ligne1(void);
int alone(t_tab *map);
/* utils.c */
int check_nb(char *str);
void destroy_ipcs(t_ipcs *ipcs);
int count_alive(t_tab *map);
void unlock(int sem_id);
int lock(int sem_id);

#endif
